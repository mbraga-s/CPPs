
#include "AMateria.hpp"

AMateria::AMateria(void): _type(NULL)
{
}

AMateria::AMateria(std::string const &type): _type(type)
{
}

AMateria::AMateria(const AMateria &copy)
{
	*this = copy;
}

AMateria &AMateria::operator=(const AMateria  &src)
{
	if (this != &src)
		this->_type = src._type;
	return(*this);
}

AMateria::~AMateria(void)
{
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* AMateria used by " << target.getName() << " *" << std::endl;
}

std::string const &AMateria::getType() const
{
	return(this->_type);
}

