
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		std::cout << std::endl << "-- Test 1 --" << std::endl;
		Bureaucrat b1("Pedro Nuno", 30);
		Bureaucrat b2("Ventura", 149);
		ShrubberyCreationForm f1("Avenida Almirante Reis");
		std::cout << b1 << b2 << std::endl;
		b2.signForm(f1);
		b1.signForm(f1);
		std::cout << f1 << std::endl;
		f1.execute(b1);
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
		RobotomyRequestForm f1("Cavaco Silva");
		std::cout << b1 << b2 << std::endl;
		b1.signForm(f1);
		f1.execute(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "-- Test 3 --" << std::endl;
		Bureaucrat b1("Marcelo Rebelo Sousa", 4);
		Bureaucrat b2("ALMIRANTE SUBMARINO", 67);
		PresidentialPardonForm f1("José Socrates");
		std::cout << std::endl << b1 << b2 << std::endl;
		f1.execute(b1);
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
		PresidentialPardonForm f1("José Socrates");
		std::cout << std::endl << b1 << b2;
		b1.signForm(f1);
		f1.execute(b1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
