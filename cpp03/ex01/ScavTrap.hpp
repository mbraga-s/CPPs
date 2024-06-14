
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap& copy);
		ScavTrap &operator=(const ScavTrap& src);
		~ScavTrap(void);

		ScavTrap(std::string name);
		void attack(const std::string& target);
		void guardGate(void);
};

#endif
