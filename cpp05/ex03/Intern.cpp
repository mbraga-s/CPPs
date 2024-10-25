
#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(const Intern &src)
{
	(void) src;
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	AForm *form = NULL;
	int i;

	std::string forms[] = { "ShrubberyCreationForm", 
	"RobotomyRequestForm" ,"PresidentialPardonForm"};

	i = 0;
	while (i < 3 && forms[i].compare(name))
		i++ ;
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break ;
		case 1:
			form = new RobotomyRequestForm(target);
			break ;
		case 2:
			form = new PresidentialPardonForm(target);
			break ;
		default:
			std::cout <<"Error: Form not found" << std::endl;
	}
	if (form)
		std::cout<< "Intern creates " << name << std::endl;
	return (form);
}
