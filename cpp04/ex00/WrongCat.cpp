
#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "A " << this->type << " has limped into your screen. (constructor)" <<std::endl;
}

WrongCat::WrongCat(const WrongCat& copy): WrongAnimal(copy)
{
	*this = copy;
	std::cout << "The " << this->type << " has split into two through ungodly magic. (copy constructor)" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& src)
{
	this->type = src.type;
	std::cout << "The " << this->type << " cheats and copies " << src.type << ". (copy assignment operator)" << std::endl;
	return(*this);
}

WrongCat::~WrongCat(void)
{
std::cout << "A " << this->type << " returned to the depths of hell. (destructor)" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << this->type << ": meeeooww?" <<std::endl;
}