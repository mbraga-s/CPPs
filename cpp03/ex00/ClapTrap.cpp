
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _hitpoints(10), _energypoints(10), _attackdmg(0)
{
	this->_name = name;
	std::cout << "ClapTrap " << this->_name << " has been created." << std::endl;
	// std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	*this = copy;
	std::cout << "ClapTrap " << this->_name << "'s clone has been created." << std::endl;
	// std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& src)
{
	this->_name = src._name;
	this->_hitpoints = src._hitpoints;
	this->_energypoints = src._energypoints;
	this->_attackdmg = src._attackdmg;
	std::cout << "ClapTrap " << this->_name << " has scanned!" << std::endl;
	// std::cout << "Copy constructor called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " has been destroyed." << std::endl;
	// std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitpoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hitpoints left. It's dead, so it can't attack." << std::endl;
		return;
	}
	if (this->_energypoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left. It can't move." << std::endl;
		return;
	}
	this->_energypoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackdmg << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitpoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hitpoints left. It's dead, so it can't be damaged further." << std::endl;
		return;
	}
	// if (this->_energypoints == 0)
	// {
	// 	std::cout << "ClapTrap " << this->_name << " has no energy left. Somehow this means it can't be damaged." << std::endl;
	// 	return;
	// }
	if (this->_hitpoints > amount)
	{
		this->_hitpoints -= amount;
		std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage!" << std::endl;
	}
	else
	{
		this->_hitpoints = 0;
		std::cout << "ClapTrap " << this->_name << " took " << amount << " points of damage and died!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitpoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hitpoints left. It's dead, so it can't repair itself." << std::endl;
		return;
	}
	if (this->_energypoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left. It can't repair itself." << std::endl;
		return;
	}
	this->_hitpoints += amount;
	this->_energypoints--;
	std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " hitpoints!" << std::endl;
}
