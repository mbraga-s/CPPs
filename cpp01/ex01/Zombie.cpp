
#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Resurrected a zombie" << std::endl;
	return;
}

Zombie::~Zombie(void)
{
	std::cout << "Returned " << _name << " to the grave..." << std::endl;
	return;
}

void	Zombie::announce(void)
{
	std::cout << _name  << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
	return;
}
