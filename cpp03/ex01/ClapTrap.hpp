
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap& copy);
		ClapTrap &operator=(const ClapTrap& src);
		~ClapTrap(void);
	
		ClapTrap(std::string name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string		_name;
		unsigned int	_hitpoints;
		unsigned int	_energypoints;
		int				_attackdmg;
};

#endif
