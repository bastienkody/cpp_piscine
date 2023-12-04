#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	zombie;

	zombie.setName(name);
	zombie.announce();
}

/*	via assign constructor	*/
void	randomChump2(std::string name)
{
	Zombie	zombie(name);

	zombie.announce();
}