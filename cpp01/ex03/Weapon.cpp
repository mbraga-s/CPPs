
#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
	return;
}

Weapon::~Weapon(void)
{
	return;
}

const std::string& Weapon::getType() const
{
	return(this->_type);
}

void	Weapon::setType(const std::string type)
{
	this->_type = type;
	return;
}
