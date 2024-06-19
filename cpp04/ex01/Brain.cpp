
#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "Thoughts";
	std::cout << "Brain constructor called." <<std::endl;
}

Brain::Brain(const Brain& copy)
{
	*this = copy;
	std::cout << "Brain copy constructor called." <<std::endl;

}

Brain &Brain::operator=(const Brain& src)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	std::cout << "Brain copy assignment operator called." <<std::endl;
	return(*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called." <<std::endl;
}

void	Brain::think(std::string thought, int i)
{
	this->_ideas[i] = thought;
}
std::string	Brain::getThought(int i) const
{
	// std::cout << &(this->_ideas[i]) <<std::endl;
	return(this->_ideas[i]);
}
