
#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	this->type = "Dog";
	std::cout << "A wild " << this->type << " dog appeared! (constructor)" <<std::endl;
}

Dog::Dog(const Dog& copy): Animal(copy)
{
	*this = copy;
	std::cout << this->type << " used Mimic! ";
	std::cout << this->type << " learned " << copy.type << "'s moves! (copy constructor)" << std::endl;
}

Dog &Dog::operator=(const Dog& src)
{
	this->type = src.type;
	std::cout << this->type << " used Transform! " << this->type << " transformed into " << this->type;
	std::cout << "! (copy assignment operator called)" << std::endl;
	return(*this);
}

Dog::~Dog(void)
{
std::cout << this->type << " fainted! (destructor)" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->type << ": woof woof" <<std::endl;
}