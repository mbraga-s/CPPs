
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name(NULL), _grade(0)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	if (this != &src)
	{
		this->_grade = src._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return(this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return(this->_grade);
}

void	Bureaucrat::incrementGrade(int value)
{
	if ((this->_grade - value) < 1)
		throw GradeTooHighException();
	else
		this->_grade -= value;
}

void	Bureaucrat::decrementGrade(int value)
{
	if ((this->_grade + value) > 150)
		throw GradeTooHighException();
	else
		this->_grade += value;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low.");
}

std::ostream &operator<<(std::ostream &src, const Bureaucrat &copy)
{
	src << copy.getName() << ", bureaucrat grade " << copy.getGrade() << "." << std::endl;
	return (src);
}
