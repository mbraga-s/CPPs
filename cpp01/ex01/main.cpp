
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	int	count;
	Zombie* horde;

	count = 5;		
	horde = zombieHorde(count, "Rotting corpse");
	for (int i = 0; i < count; i++)
		horde[i].announce();
	delete [] horde;
	return (0);
}
