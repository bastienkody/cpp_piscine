#include "ClapTrap.hpp"
#include "FragTrap.hpp"

inline void	print(FragTrap &a, FragTrap &b, FragTrap &c)
{
	std::cout << "------------------------------------------------" << std::endl;
	a.fullDisplay();
	b.fullDisplay();
	c.fullDisplay();
	std::cout << "------------------------------------------------" << std::endl;
}

inline void	realAttack(FragTrap &stricker, FragTrap &target)
{
	stricker.attack(target.getName());
	target.takeDamage(stricker.getAttackDamage());
}

int	main(void)
{
	FragTrap	a("A");	
	FragTrap	b;
	FragTrap	c(a);

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

	a.highFivesGuys();
	b.highFivesGuys();
	c.highFivesGuys();
}
