#include "Zombie.hpp"

void	announceHorde(int size, Zombie *horde)
{
	for (int i = 0; i < size; i++)
		horde[i].announce();
}

int	main(void)
{
	Zombie	*zombies_0 = zombieHorde(0, "Joe");
	Zombie	*zombies_1 = zombieHorde(1, "OzdenAkca");
	Zombie	*zombies_2 = zombieHorde(2, "MariaTambien");
	Zombie	*zombies_10 = zombieHorde(10, "LeGouvernementFrancaisMeFaitHonte");

	announceHorde(1, zombies_1);
	announceHorde(2, zombies_2);
	announceHorde(10, zombies_10);

	delete [] zombies_0;
	delete [] zombies_1;
	delete [] zombies_2;
	delete [] zombies_10;
}