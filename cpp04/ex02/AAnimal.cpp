
#include "AAnimal.hpp"

AAnimal::AAnimal(void): type("Generic AAnimal")
{
	std::cout << this->type << " constructor called." <<std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
	*this = copy;
	std::cout << type << " copy constructor called." <<std::endl;

}

AAnimal &AAnimal::operator=(const AAnimal& src)
{
	this->type = src.type;
	std::cout << type << " copy assignment operator called." <<std::endl;
	return(*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << this->type << " destructor called." <<std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << this->type << ": *Generic growls and chirps*" <<std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}