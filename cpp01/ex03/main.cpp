#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	std::cout << "\033[4mHuman A part :\033[0m" << std::endl;
{
	Weapon	club = Weapon("crude spiked club");
	HumanA	bob("bob", club);

	bob.attack();
	club.setType("some other type of club");
	bob.attack();
}
	std::cout << "\033[4mHuman B part :\033[0m" << std::endl;
{
	Weapon	club = Weapon("crude spiked club");
	HumanB	jim("Jim");

	jim.setWeapon(club);
	jim.attack();
	club.setType("yet another type of club");
	jim.attack();
}
	return (0);
}
