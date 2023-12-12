#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	a("A");
	a.fullDisplay();
	a.attack("enemy");
	a.whoAmI();
	a.guardGate();
	a.highFivesGuys();
	std::cout << "------------------------------------------------" << std::endl;

	DiamondTrap b;
	b.whoAmI();
	
	b = a;
	b.whoAmI();
	b.fullDisplay();
	b.attack("oponent");
	b.guardGate();
	b.highFivesGuys();
	std::cout << "------------------------------------------------" << std::endl;
}
