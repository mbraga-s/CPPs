
#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		return (1);
	}

	RPN stack;

	if (!stack.parse_input(argv[1]) && argv[1][0])
		stack.reverse_polish(argv[1]);
	else
		std::cerr << "Error: Parse" << std::endl;
	return (0);
}