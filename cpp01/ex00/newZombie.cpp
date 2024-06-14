
#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie* corpse = new Zombie(name);

	return (corpse);
}
