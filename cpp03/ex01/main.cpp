
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap r1("AutoBot");
	ClapTrap r2("PikachuBot");

	r1.attack("Decepticon");
	r2.attack("CharmanderBot");
	r2.takeDamage(7);
	std::cout << std::endl;
	r1.attack("Decepticon");
	r2.attack("CharmanderBot");
	r2.beRepaired(2);
	std::cout << std::endl;
	r1.attack("Decepticon");
	r2.attack("CharmanderBot");
	r2.takeDamage(6);
	r2.takeDamage(3);
	r2.beRepaired(2);
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		r1.attack("Decepticon");
	std::cout << std::endl;
	return (0);
}
