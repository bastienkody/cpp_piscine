#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

inline void	print(ScavTrap &a, ScavTrap &b, ScavTrap &c)
{
	std::cout << "------------------------------------------------" << std::endl;
	a.fullDisplay();
	b.fullDisplay();
	c.fullDisplay();
	std::cout << "------------------------------------------------" << std::endl;
}

inline void	realAttack(ScavTrap &stricker, ScavTrap &target)
{
	stricker.attack(target.getName());
	target.takeDamage(stricker.getAttackDamage());
}

int	main(void)
{
	ScavTrap	a("A");	
	ScavTrap	b;
	ScavTrap	c(a);

	b = a;

	print(a, b, c);

	b.setName("B");
	c.setName("C");

	print(a, b, c);

	for (int i = 0; i < 6; i++)
		realAttack(a, b);

	print(a, b, c);

	a.beRepaired(3);
	b.beRepaired(3);
	c.beRepaired(3);

	print(a, b, c);

	a.guardGate();
	b.guardGate();
	c.guardGate();
}
