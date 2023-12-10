#include "FragTrap.hpp"

FragTrap::~FragTrap()
{
	std::cout << "Frag Destructor" << std::endl;
}

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Frag Default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) :	ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "Frag Parametric constructor" << std::endl;
}

FragTrap::FragTrap(FragTrap &src) : ClapTrap(src)
{
	std::cout << "Frag Copy constructor" << std::endl;
}

/*	Copy operator (cant be in init list)	*/
FragTrap & FragTrap::operator=(FragTrap &rhs)
{
	ClapTrap::operator=(rhs); 

	std::cout << "Frag Copy operator" << std::endl;
	return (*this);			
}

/*	scavtrap special fct	*/
void	FragTrap::highFivesGuys(void) const
{
	if (this->checkHitPoints())
		std::cout << "FragTrap " << _name << " high fives anyone in the room" << std::endl;
	else
		std::cout << "FragTrap " << _name << " is dead, he can't high five" << std::endl;
}