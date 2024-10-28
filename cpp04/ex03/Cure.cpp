
#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
}

Cure::~Cure(void)
{
}

Cure::Cure(const Cure &copy)
{
	*this = copy;
}

Cure &Cure::operator=(const Cure  &src)
{
	if (this != &src)
		this->_type = src._type;
	return(*this);
}

AMateria* Cure::clone() const
{
	Cure *clone = new Cure();
	if (!clone)
		return (NULL);
	return (clone);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
