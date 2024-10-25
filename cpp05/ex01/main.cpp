
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		std::cout << std::endl << "-- Test 1 --" << std::endl;
		Bureaucrat b1("Pedro Nuno", 30);
		Bureaucrat b2("Ventura", 67);
		Form f1("Orçamento do Estado 2025", 50, 10);
		std::cout << b1 << b2 << f1 << std::endl;
		b2.signForm(f1);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
		std::cout << f1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "-- Test 2 --" << std::endl;
		Form f1("Orçamento do Estado 2026", 0, 1);
		std::cout << f1 << std::endl;
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
		std::cout << std::endl << b1 << b2;
		std::cout << std::endl << "Decrementing " << b1.getName() << "'s grade by 26" << std::endl;
		b1.decrementGrade(26);
		std::cout << b1;
		std::cout << "Incrementing " << b2.getName() << "'s grade by 68" << std::endl;
		b1.incrementGrade(68);
		std::cout << b2;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
