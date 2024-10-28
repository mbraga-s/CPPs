
#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
}

Ice::~Ice(void)
{
}

Ice::Ice(const Ice &copy)
{
	*this = copy;
}

Ice &Ice::operator=(const Ice  &src)
{
	if (this != &src)
		this->_type = src._type;
	return(*this);
}

AMateria* Ice::clone() const
{
	Ice *clone = new Ice();
	if (!clone)
		return (NULL);
	return (clone);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots and ice bolt at " << target.getName() << " *" << std::endl;
}
