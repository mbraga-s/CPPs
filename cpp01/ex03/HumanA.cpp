
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _ref(weapon), _name(name)
{
	return;
}

HumanA::~HumanA(void)
{
	return;
}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _ref.getType() << std::endl;
}
