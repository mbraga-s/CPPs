
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for(int i = 0; i < 4; i++)
		this->inv[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	*this = copy;
}

MateriaSource::~MateriaSource(void)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->inv[i])
			delete this->inv[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	if (this != &src)
	{
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

void MateriaSource::learnMateria(AMateria *m)
{
	for(int i = 0; i < 4; i++)
	{
		if(!this->inv[i])
		{
			this->inv[i] = m;
			std::cout << "Materia " << m->getType() << " learned." << std::endl;
			return ;
		}
	}
	std::cout << "Materia " << m->getType() << " was unable to be learned." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	bool flag = 0;
	int i = 0;
	while(i < 4)
	{
		if (this->inv[i] && !this->inv[i]->getType().compare(type))
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 1)
	{
		std::cout << "Created Materia of type " << type << std::endl;
		return (this->inv[i]->clone());
	}
	std::cout << "Failed to created Materia of type " << type << std::endl;
	return (0);
}
