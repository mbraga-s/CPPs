
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		std::cout << std::endl << "-- Test 1 --" << std::endl;
		Bureaucrat b1("Pedro Nuno Santos", 30);
		Bureaucrat b2("Ventura", 67);
		std::cout << b1 << b2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "-- Test 2 --" << std::endl;
		Bureaucrat b1("Pedro Nuno Santos", 30);
		Bureaucrat b2("Ventura", 200);
		std::cout << b1 << b2 << std::endl;
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
		std::cout << b1 << b2;
		std::cout << std::endl << "Decrementing " << b1.getName() << "'s grade by 16" << std::endl;
		b1.decrementGrade(16);
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
