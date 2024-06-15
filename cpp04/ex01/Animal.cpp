
#include "Animal.hpp"

Animal::Animal(void): type("Generic animal")
{
	std::cout << this->type << " constructor called." <<std::endl;
}

Animal::Animal(const Animal& copy)
{
	*this = copy;
	std::cout << type << " copy constructor called." <<std::endl;

}

Animal &Animal::operator=(const Animal& src)
{
	this->type = src.type;
	std::cout << type << " copy assignment operator called." <<std::endl;
	return(*this);
}

Animal::~Animal(void)
{
	std::cout << this->type << " destructor called." <<std::endl;
}

void Animal::makeSound() const
{
	std::cout << this->type << ": *Generic growls and chirps*" <<std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}