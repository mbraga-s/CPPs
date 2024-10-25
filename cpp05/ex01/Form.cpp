
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name(NULL), _flag(false), _signgrade(0), _execgrade(0)
{
}

Form::Form(std::string name, int signgrade, int execgrade): _name(name), _signgrade(signgrade), _execgrade(execgrade)
{
	if (signgrade < 1 || execgrade < 1)
		throw GradeTooHighException();
	else if (signgrade > 150 || execgrade > 150)
		throw GradeTooLowException();
	this->_flag = false;
}

Form::~Form()
{
}

Form::Form(const Form &copy): _name(copy.getName()), _signgrade(copy.getSignGrade()), _execgrade(copy.getExecGrade())
{
	*this = copy;
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
	{
		this->_flag = src.getSignGrade();
	}
	return (*this);
}

std::string Form::getName(void) const
{
	return(this->_name);
}

int	Form::getSignGrade(void) const
{
	return(this->_signgrade);
}

int	Form::getExecGrade(void) const
{
	return(this->_execgrade);
}

bool	Form::getFlag(void) const
{
	return(this->_flag);
}

void Form::beSigned(const Bureaucrat &signee)
{
	if(signee.getGrade() <= this->_signgrade)
		this->_flag = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low.");
}

std::ostream &operator<<(std::ostream &src, const Form &copy)
{
	src << std::endl << "-- Form details --" << std::endl;
	src << "Name: " << copy.getName() << std::endl;
	src << "Min grade to sign: " << copy.getSignGrade() << std::endl;
	src << "Min grade to execute: " << copy.getExecGrade() << std::endl;
	src << "Signed state: " << copy.getFlag() << std::endl;
	return (src);
}
