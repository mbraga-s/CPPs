
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Resurrected " << _name << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "Returned  " << _name << " to the grave..." << std::endl;
	return;
}

void	Zombie::announce(void)
{
	std::cout << _name  << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}