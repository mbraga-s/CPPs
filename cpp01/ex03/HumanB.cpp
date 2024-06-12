
#include "HumanB.hpp"

HumanB::HumanB(std::string name): _ref(NULL)
{
	_name = name;
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void	HumanB::attack(void)
{
	if (!this->_ref)
		std::cout << _name << " attacks with their firsts" << std::endl;
	else
		std::cout << _name << " attacks with their " << this->_ref->getType() << std::endl;
	return;
}

void	HumanB::setWeapon(Weapon& type)
{
	this->_ref = &type;
	return;
}