
#include "Animal.hpp"

Animal::Animal(void): type("Generic animal")
{
	std::cout << "Animal constructor called." <<std::endl;
}

Animal::Animal(const Animal& copy)
{
	*this = copy;
	std::cout << "Animal copy constructor called." <<std::endl;
}

Animal &Animal::operator=(const Animal& src)
{
	this->type = src.type;
	std::cout << "Animal copy assignment operator called." <<std::endl;
	return(*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called." <<std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal: *Generic growls and chirps*" <<std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}