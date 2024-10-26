
#include <cmath>
#include "Array.hpp"
#include <iostream>

int main(void)
{
	Array<int> a(5);
	for (int i = 0; i < 5; i++)
		a[i] = i;
	for (int i = 0; i < 5; i++)
		std::cout << a[i] << std::endl;
	std::cout << std::endl;
	Array<int> b(5);
	b = a;
	for (int i = 0; i < 5; i++)
		std::cout << b[i] << std::endl;
	std::cout << std::endl;
	Array<int> c(b);
	for (int i = 0; i < 5; i++)
		std::cout << c[i] << std::endl;
}