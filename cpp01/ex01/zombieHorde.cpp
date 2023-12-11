#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	try
	{
			Zombie	*zombies = new Zombie [N];
			for (int i = 0; i < N; i++)
				zombies[i].setName(name);
			return (zombies);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
		if (N < 0)
			std::cerr << ": N can't be negative here, stupid user" << '\n';
		else
			std::cerr << ": feels like no more memory on the heap??" << '\n';
		return (NULL);
	}
}
