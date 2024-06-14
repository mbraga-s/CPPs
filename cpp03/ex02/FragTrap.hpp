
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const FragTrap& copy);
		FragTrap &operator=(const FragTrap& src);
		~FragTrap(void);

		FragTrap(std::string name);
		void highFivesGuys(void);
};

#endif