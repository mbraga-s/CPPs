
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap r1("Autobot");
	FragTrap r2("Decepticon");

	std::cout << std::endl;
	r1.guardGate();
	std::cout << std::endl;
	std::cout << "A wild Decepticon appered!" << std::endl;
	r2.highFivesGuys();
	std::cout << std::endl;
	r1.attack("Decepticon");
	r2.takeDamage(20);
	r2.highFivesGuys();
	std::cout << std::endl;
	r1.attack("Decepticon");
	r2.takeDamage(20);
	r2.highFivesGuys();
	std::cout << std::endl;
	r1.attack("Decepticon");
	std::cout << "It was a critical hit!" << std::endl;
	r2.takeDamage(60);
	r2.highFivesGuys();
	std::cout << std::endl;
	r1.attack("Decepticon");
	r2.takeDamage(20);
	r2.highFivesGuys();
	std::cout << std::endl;
	return (0);
}
