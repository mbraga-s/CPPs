
#include <iostream>

int	main(void)
{
	std::string		str;
	std::string*	ptr;
	std::string&	ref = str;

	str = "HI THIS IS BRAIN";
	ptr = &str;

	std::cout << &str << std::endl;
	std::cout << ptr << std::endl;
	std::cout << &ref << std::endl;
	std::cout << std::endl;
	std::cout << str << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << ref << std::endl;
	return (0);
}