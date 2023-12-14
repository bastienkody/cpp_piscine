#include "ScavTrap.hpp"

ScavTrap::~ScavTrap()
{
	std::cout << "Scav Destructor" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Scav Default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : 	ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "Scav Parametric constructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &src) : ClapTrap(src)
{
	std::cout << "Scav Copy constructor" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap &rhs)
{
	ClapTrap::operator=(rhs); 
	std::cout << "Scav Copy operator" << std::endl;
	return (*this);			
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->checkHitPoints())
		return (static_cast<void>(std::cout << _name << " has no hit point, can't attack." << std::endl));
	if (!this->checkEnergyPoints())
		return (static_cast<void>(std::cout << _name << " has no energy point, can't attack." << std::endl));
	
	_energyPoints -=1;
	std::cout << "ScavTrap " << _name << " punched " << target << " with a oustanding power of ";
	std::cout  << _attackDamage << " damage points wich might stunt the opponent" << std::endl;
}

void	ScavTrap::guardGate() const
{
	if (this->checkHitPoints())
		std::cout << "ScavTrap " << _name << " is now in Gate keeper mode (no energy point needed)" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is dead, he can't guard anything" << std::endl;
}
