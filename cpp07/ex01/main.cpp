
#include "iter.hpp"
# include <iostream>
#include <string>

void subtract(int &i)
{
	i = i - 2;
}

int	main(void)
{
	int	array[5] = {0, 1, 2, 3, 4};

	iter(array, 5, subtract);
	for (int i = 0; i < 5; i++)
	{
		std::cout << array[i] <<std::endl;
	}
	return (0);
}