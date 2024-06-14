
#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void) 
{
    Zombie body1("Bart");
    body1.announce();
    Zombie* body2 = newZombie("Marge");
    body2->announce();
    delete body2;
    randomChump("Homer");
    return (0);
}