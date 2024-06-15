
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("Generic WrongAnimal")
{
	std::cout << this->type << " constructor called." <<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	*this = copy;
	std::cout << type << " copy constructor called." <<std::endl;

}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& src)
{
	this->type = src.type;
	std::cout << type << " copy assignment operator called." <<std::endl;
	return(*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << this->type << " destructor called." <<std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << this->type << ": *Generic disturbing sounds*" <<std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}