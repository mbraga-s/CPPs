
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdmg = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdmg = 20;
	std::cout << "ScavTrap unit " << this->_name << " has been created." << std::endl;
	// std::cout << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy): ClapTrap(copy)
{
	*this = copy;
	std::cout << "ScavTrap unit " << this->_name << "'s clone has been created." << std::endl;
	// std::cout << "Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& src)
{
	this->_name = src._name;
	this->_hitpoints = src._hitpoints;
	this->_energypoints = src._energypoints;
	this->_attackdmg = src._attackdmg;
	std::cout << "ScavTrap unit " << this->_name << " has scanned!" << std::endl;
	// std::cout << "Copy constructor called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap unit " << this->_name << " has been destroyed." << std::endl;
	// std::cout << "Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_hitpoints == 0)
	{
		std::cout << this->_name << " has no hitpoints left. It's broken... it can't attack." << std::endl;
		return;
	}
	if (this->_energypoints == 0)
	{
		std::cout << this->_name << " has no energy left. It's powered down." << std::endl;
		return;
	}
	this->_energypoints--;
	std::cout << "ScavTrap unit " << this->_name << " attacks " << target << " causing " << this->_attackdmg << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitpoints == 0)
	{
		std::cout << this->_name << " has no hitpoints left. It's broken..." << std::endl;
		return;
	}
	if (this->_energypoints == 0)
	{
		std::cout << this->_name << " has no energy left. It's powered down." << std::endl;
		return;
	}
	this->_energypoints--;
	std::cout << "ScavTrap unit " << this->_name << " has entered Gate Keeper mode." << std::endl;
}
