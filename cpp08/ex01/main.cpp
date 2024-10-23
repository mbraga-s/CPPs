
#include "Span.hpp"

int main(void)
{
	try 
	{
		Span array(5);

		array.addNumber(1);
		array.addNumber(41);
		array.addNumber(7);
		array.addNumber(23);
		array.addNumber(15);
		std::cout << "Shortest span: " << array.shortestSpan() << std::endl;
		std::cout << "Longest span: " << array.longestSpan() << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	try 
	{
		Span array(2);

		array.addNumber(11);
		array.addNumber(570);
		array.addNumber(24);
		std::cout << "Shortest span: " << array.shortestSpan() << std::endl;
		std::cout << "Longest span: " << array.longestSpan() << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	try
	{
		Span new_span(10000);
		std::vector<int> vec(10000);

		for (int i = 0; i < 10000; i++)
			vec[i] = i;
		new_span.addNumbers(vec.begin(), vec.end());
		std::cout << "Shortest span: " << new_span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << new_span.longestSpan() << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	return (0);
}