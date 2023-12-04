#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	Zombie	*zombie;

	zombie = new Zombie;
	zombie->setName(name);
	return (zombie);
}

/* or simply via the constructor	*/
Zombie*	newZombie2(std::string name)
{
	return (new Zombie(name));
}