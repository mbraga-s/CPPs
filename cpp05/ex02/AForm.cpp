
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name(NULL), _flag(false), _signgrade(0), _execgrade(0)
{
}

AForm::AForm(std::string name, int signgrade, int execgrade): _name(name), _signgrade(signgrade), _execgrade(execgrade)
{
	if (signgrade < 1 || execgrade < 1)
		throw GradeTooHighException();
	else if (signgrade > 150 || execgrade > 150)
		throw GradeTooLowException();
	this->_flag = false;
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &copy): _name(copy.getName()), _signgrade(copy.getSignGrade()), _execgrade(copy.getExecGrade())
{
	*this = copy;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		this->_flag = src.getSignGrade();
	}
	return (*this);
}

std::string AForm::getName(void) const
{
	return(this->_name);
}

int	AForm::getSignGrade(void) const
{
	return(this->_signgrade);
}

int	AForm::getExecGrade(void) const
{
	return(this->_execgrade);
}

bool	AForm::getFlag(void) const
{
	return(this->_flag);
}

void AForm::beSigned(const Bureaucrat &signee)
{
	if(signee.getGrade() <= this->_signgrade)
		this->_flag = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if(this->_flag == false)
		throw GradeTooLowException();
	else if (executor.getGrade() > this->_execgrade)
		throw FormNotSigned();
	else
		this->action();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low.");
}

const char *AForm::FormNotSigned::what() const throw()
{
	return ("Error: Form not signed.");
}

std::ostream &operator<<(std::ostream &src, const AForm &copy)
{
	src << std::endl << "-- Form details --" << std::endl;
	src << "Name: " << copy.getName() << std::endl;
	src << "Min grade to sign: " << copy.getSignGrade() << std::endl;
	src << "Min grade to execute: " << copy.getExecGrade() << std::endl;
	src << "Signed state: " << copy.getFlag() << std::endl;
	return (src);
}
