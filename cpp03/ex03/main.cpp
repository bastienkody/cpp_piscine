#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	a("A");
	a.whoAmI();
	a.guardGate();
	a.highFivesGuys();
	std::cout << "------------------------------------------------" << std::endl;

	DiamondTrap b;
	b.whoAmI();
	
	b = a;
	b.whoAmI();
	b.guardGate();
	b.highFivesGuys();
	std::cout << "------------------------------------------------" << std::endl;
}
