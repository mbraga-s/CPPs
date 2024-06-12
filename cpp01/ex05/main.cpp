
#include "Harl.hpp"

int	main(void)
{
	Harl	dude;

	std::cout << "\nDEBUG:" << std::endl;
	dude.complain("DEBUG");
	std::cout << "\nINFO:" << std::endl;
	dude.complain("INFO");
	std::cout << "\nWARNING:" << std::endl;
	dude.complain("WARNING");
	std::cout << "\nERROR:" << std::endl;
	dude.complain("ERROR");
	std::cout << "\nINVALID:" << std::endl;
	dude.complain("INVALID");
	return (0);
}