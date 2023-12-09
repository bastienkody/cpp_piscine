#include "ClapTrap.hpp"

inline void	print(ClapTrap &a, ClapTrap &b)
{
	std::cout << "------------------------------------------------" << std::endl;
	a.fullDisplay();
	b.fullDisplay();
	std::cout << "------------------------------------------------" << std::endl;
}

inline void	realAttack(ClapTrap &stricker, ClapTrap &target)
{
	stricker.attack(target.getName());
	target.takeDamage(stricker.getAttackDamage());
}

int	main(void)
{
	ClapTrap	a("A");
	ClapTrap	b;

	b = a;
	b.setName("B");

	print(a, b);

	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());

	b.setAttackDamage(8);
	realAttack(b, a);

	print(a, b);

	a.setEnergyPoints(0);
	a.attack(b.getName());

	print(a, b);

	realAttack(b, a);
	realAttack(b, a);

	print(a, b);

	a.setEnergyPoints(4);
	a.beRepaired(3);
	b.beRepaired(1);

	print(a,b);
}
