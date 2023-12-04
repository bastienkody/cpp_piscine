#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;

	zombie = newZombie("foo");
	delete zombie;
	zombie = newZombie2("bar");
	delete zombie;

	zombie = newZombie("foolish");
	zombie->announce();
	delete zombie;
	zombie = newZombie2("bartender");
	zombie->announce();
	delete zombie;

	randomChump("foobar");
	randomChump2("barfoo");
}