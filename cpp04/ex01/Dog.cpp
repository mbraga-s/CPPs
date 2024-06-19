
#include "Dog.hpp"

Dog::Dog(void): Animal()
{
	this->type = "Dog";
	this->_cerebrum = new Brain();
	std::cout << "A wild " << this->type << " appeared! (constructor)" <<std::endl;
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
	if(!this->_cerebrum)
		this->_cerebrum = new Brain();
	*this->_cerebrum = *src._cerebrum;
	std::cout << this->type << " used Transform! " << this->type << " transformed into " << this->type;
	std::cout << "! (copy assignment operator called)" << std::endl;
	return(*this);
}

Dog::~Dog(void)
{
	delete this->_cerebrum;
	std::cout << this->type << " fainted! (destructor)" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->type << ": woof woof" <<std::endl;
}

void	Dog::setIdea(std::string idea, int i)
{
	this->_cerebrum->think(idea, i);
}

std::string	Dog::getIdea(int i) const
{
	return(this->_cerebrum->getThought(i));
}