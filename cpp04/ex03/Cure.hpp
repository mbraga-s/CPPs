
#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <iostream>

class Cure: public AMateria
{
	public:
		Cure(void);
		~Cure(void);
		Cure(const Cure &copy);
		Cure &operator=(const Cure &src);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

	private:

};

#endif