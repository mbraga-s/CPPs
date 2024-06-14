
#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap r1("Autobot");
	ScavTrap r2("Decepticon");

	std::cout << std::endl;
	r1.guardGate();
	std::cout << std::endl;
	std::cout << "A wild Decepticon appered!" << std::endl;
	std::cout << std::endl;
	r1.attack("Decepticon");
	r2.takeDamage(20);
	r2.attack("Autobot");
	r1.takeDamage(20);
	std::cout << std::endl;
	r1.attack("Decepticon");
	r2.takeDamage(20);
	r2.beRepaired(10);
	std::cout << std::endl;
	r1.attack("Decepticon");
	std::cout << "It was a critical hit!" << std::endl;
	r2.takeDamage(60);
	r2.attack("Autobot");
	r1.takeDamage(20);
	std::cout << std::endl;
	r1.attack("Decepticon");
	r2.takeDamage(20);
	r2.attack("Autobot");
	r1.takeDamage(20);
	std::cout << std::endl;
	return (0);
}
