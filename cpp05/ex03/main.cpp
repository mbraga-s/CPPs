
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		std::cout << std::endl << "-- Test 1 --" << std::endl;
		Bureaucrat b1("Pedro Nuno", 30);
		Bureaucrat b2("Ventura", 149);
		Intern i1;
		AForm *temp1 = i1.makeForm("ShrubberyCreationForm", "Avenida Almirante Reis");
		std::cout << b1 << b2 << std::endl;
		if (temp1)
		{
			b2.signForm(*temp1);
			b1.signForm(*temp1);
			std::cout << *temp1 << std::endl;
			temp1->execute(b1);
			delete temp1;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "-- Test 2 --" << std::endl;
		Bureaucrat b1("Pedro Nuno", 30);
		Bureaucrat b2("Ventura", 149);
		Intern i1;
		AForm *temp1 = i1.makeForm("RobotomyRequestForm", "Cavaco Silva");
		std::cout << b1 << b2 << std::endl;
		if (temp1)
		{
			b1.signForm(*temp1);
			temp1->execute(b1);
			delete temp1;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "-- Test 4 --" << std::endl;
		Bureaucrat b1("Marcelo Rebelo Sousa", 4);
		Bureaucrat b2("ALMIRANTE SUBMARINO", 67);
		Intern i1;
		AForm *temp1 = i1.makeForm("PresidentialPardonForm", "José Socrates");
		std::cout << std::endl << b1 << b2;
		if (temp1)
		{
			b1.signForm(*temp1);
			temp1->execute(b1);
			delete temp1;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
