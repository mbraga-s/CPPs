
#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <iostream>

class ICharacter;

class Ice: public AMateria
{
	public:
		Ice(void);
		~Ice(void);
		Ice(const Ice &copy);
		Ice &operator=(const Ice &src);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

	private:

};

#endif
