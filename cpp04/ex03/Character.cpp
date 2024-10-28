
#include "Character.hpp"

Character::Character(void): _name("Unknown")
{
	for(int i = 0; i < 4; i++)
		this->inv[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	for(int i = 0; i < 4; i++)
		this->inv[i] = NULL;
}

Character::~Character(void)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->inv[i])
			delete this->inv[i];
	}
}

Character::Character(const Character &copy)
{
	for(int i = 0; i < 4; i++)
		this->inv[i] = NULL;
	*this = copy;
}

Character &Character::operator=(const Character &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for(int i = 0; i < 4; i++)
		{
			if (this->inv[i])
				delete this->inv[i];
			this->inv[i] = NULL;
			this->inv[i] = src.inv[i]->clone();
		}
	}
	return (*this);
}

std::string const & Character::getName(void) const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for(int i = 0; i < 4; i++)
	{
		if(!this->inv[i])
		{
			this->inv[i] = m;
			std::cout << "Materia " << m->getType() << " equipped in slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "Materia " << m->getType() << " not equipped! Inventory full!" << std::endl;
}

void Character::unequip(int idx)
{
	if(idx < 4 && idx >= 0 && this->inv[idx])
	{
		std::cout << "Materia " << this->inv[idx]->getType() << " was unequipped" << std::endl;
		this->inv[idx] = 0;
		return ;
	}
	std::cout << "Unable to unequip requested Materia." << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 4 && idx >= 0 && this->inv[idx])
		this->inv[idx]->use(target);
	else if (idx > 4)
		std::cout << "Only 4 Materias are known!" << std::endl;
	else
		std::cout << "I need to know Materias!" << std::endl;
}
