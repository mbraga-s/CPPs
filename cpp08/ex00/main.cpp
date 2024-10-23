
#include "easyfind.hpp"
#include <iostream>
#include <list>


int	main(void)
{
	std::list<int> lst;

	lst.push_back(2);
	lst.push_back(30);
	lst.push_back(42);
	lst.push_back(57);
	lst.push_back(14);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 42);
		std::cout << "Found value " << *it << std::endl;
		std::list<int>::iterator it2 = easyfind(lst, 52);
		std::cout << "Found value " << *it2 << std::endl;  
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}