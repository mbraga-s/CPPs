
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy)
{
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return(this->_target);
}

void RobotomyRequestForm::action(void) const
{
	std::cout << "*Drilling noises*" << std::endl;
	srand(time(NULL));
	if ((rand()) % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
  	else
		std::cout << "Robotomy on " << this->_target << " failed." << std::endl;
}
