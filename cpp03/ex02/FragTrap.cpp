
#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackdmg = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_name = name;
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackdmg = 30;
	std::cout << "FragTrap unit " << this->_name << " has been created." << std::endl;
	// std::cout << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy): ClapTrap(copy)
{
	*this = copy;
	std::cout << "FragTrap unit " << this->_name << "'s clone has been created." << std::endl;
	// std::cout << "Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& src)
{
	this->_name = src._name;
	this->_hitpoints = src._hitpoints;
	this->_energypoints = src._energypoints;
	this->_attackdmg = src._attackdmg;
	std::cout << "FragTrap unit " << this->_name << " has scanned!" << std::endl;
	// std::cout << "Copy constructor called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap unit " << this->_name << " has been destroyed." << std::endl;
	// std::cout << "Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_hitpoints == 0)
	{
		std::cout << this->_name << " has no hitpoints left. Rest in pieces..." << std::endl;
		return;
	}
	if (this->_energypoints == 0)
	{
		std::cout << this->_name << " has no energy left. Maybe charge it next time?>." << std::endl;
		return;
	}
	this->_energypoints--;
	std::cout << "FragTrap unit " << this->_name << " wants to high-five people, so it does." << std::endl;
}