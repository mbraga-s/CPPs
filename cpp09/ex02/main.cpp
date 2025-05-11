
#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char **argv) 
{
	if (argc < 2) 
	{
		std::cerr << "Error: Too few arguments" << std::endl;
		return (1);
	}

	PmergeMe pm;

	std::clock_t start = clock();
	if(pm.add_to_vector(argc, argv))
		return (1);

	std::cout << "Before: ";
	pm.print_vector();

	pm.ford_johnson_vector(pm.s_vector);

	std::clock_t end = std::clock();

	std::cout << "After: ";
	pm.print_vector();
	double time = (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);
	std::cout << "Time to process a range of " << pm.s_vector.size() << " elements with std::vector: " << time << " us" << std::endl;

	start = clock();
	if(pm.add_to_list(argc, argv))
		return (1);

	// std::cout << "Before (list): ";
	// pm.print_list();

	pm.ford_johnson_list(pm.s_list);

	end = std::clock();

	// std::cout << "After (list): ";
	// pm.print_list();
	time = (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000);
	std::cout << "Time to process a range of " << pm.s_list.size() << " elements with std::list: " << time << " us" << std::endl;

	return (0);
}
