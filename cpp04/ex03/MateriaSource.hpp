
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &copy);
		~MateriaSource(void);
		MateriaSource &operator=(const MateriaSource &src);

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria *inv[4];
};

#endif