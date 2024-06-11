
#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie* corpse;

	corpse = new Zombie(name);
	return (corpse);
}
