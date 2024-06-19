
#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	this->type = "Cat";
	this->_cerebrum = new Brain();
	std::cout << "A " << this->type << " has wandered into your screen. (constructor)" <<std::endl;
}

Cat::Cat(const Cat& copy): Animal(copy)
{
	*this = copy;
	std::cout << "The " << this->type << " has split into two through mitosis. (copy constructor)" << std::endl;
}

Cat &Cat::operator=(const Cat& src)
{
	this->type = src.type;
	if(!this->_cerebrum)
		this->_cerebrum = new Brain();
	*this->_cerebrum = *src._cerebrum;
	std::cout << "The " << this->type << " has no individuality and copied the " << src.type << ". (copy assignment operator)" << std::endl;
	return(*this);
}

Cat::~Cat(void)
{
	delete(this->_cerebrum);
	std::cout << "A " << this->type << " vanished in a puff of smoke. (destructor)" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << this->type << ": meeeooww" <<std::endl;
}

void	Cat::setIdea(std::string idea, int i)
{
	this->_cerebrum->think(idea, i);
}

std::string	Cat::getIdea(int i) const
{
	return(this->_cerebrum->getThought(i));
}