
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

class Character : public ICharacter
{
	public:
		Character(void);
		Character(std::string name);
		~Character(void);
		Character(const Character &copy);
		Character &operator=(const Character &src);

		virtual std::string const & getName(void) const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	private:
		AMateria *inv[4];
		std::string _name;
};


#endif
