#include "ClapTrap.hpp"

ClapTrap::~ClapTrap() 
{
	std::cout << "Clap Destructor" << std::endl;
}

/*	construction	*/
ClapTrap::ClapTrap()
{
	_name = "";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "Clap Default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	std::cout << "Clap Parametric constructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &src)
{
	*this = src;
	std::cout << "Clap Copy constructor" << std::endl;
}


ClapTrap & ClapTrap::operator=(ClapTrap &rhs)
{
	if (this != &rhs)
	{
		_name = rhs.getName();
		_hitPoints = rhs.getHitPoints();
		_energyPoints = rhs.getEnergyPoints();
		_attackDamage = rhs.getAttackDamage();
	}
	std::cout << "Clap Copy operator" << std::endl;
	return (*this);
}

/*	getters	*/
std::string		ClapTrap::getName() const			{return (_name);}
unsigned int	ClapTrap::getHitPoints() const		{return (_hitPoints);}
unsigned int	ClapTrap::getEnergyPoints() const	{return (_energyPoints);}
unsigned int	ClapTrap::getAttackDamage() const	{return (_attackDamage);}

/*	setters	*/
void	ClapTrap::setName(const std::string name)			{_name = name;}
void	ClapTrap::setHitPoints(const unsigned int hp)		{_hitPoints = hp;}
void	ClapTrap::setEnergyPoints(const unsigned int eng)	{_energyPoints = eng;}
void	ClapTrap::setAttackDamage(const unsigned int att)	{_attackDamage = att;}

/*	checkers	*/
bool	ClapTrap::checkHitPoints() const 		{return (_hitPoints > 0);}
bool	ClapTrap::checkEnergyPoints() const		{return (_energyPoints > 0);}

/*	display	*/
void	ClapTrap::fullDisplay() const
{
	std::cout << "Clap Trap " << _name << " with hp:" << _hitPoints << ", energy:" ;
	std::cout << _energyPoints << ", and attack :" << _attackDamage << std::endl;
}

/*	actions	*/
void	ClapTrap::attack(const std::string& target)
{
	if (!this->checkHitPoints())
		return (static_cast<void>(std::cout << _name << " has no hit point, can't attack." << std::endl));
	if (!this->checkEnergyPoints())
		return (static_cast<void>(std::cout << _name << " has no energy point, can't attack." << std::endl));
	
	_energyPoints -=1;
	std::cout << "ClapTrap " << _name << " attacks " << target << " with a strenght of ";
	std::cout  << _attackDamage << " damage points" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	effectiveDamage = 0;

	if (this->checkHitPoints())
	{
		amount <= _hitPoints ? effectiveDamage = amount : effectiveDamage = _hitPoints;
		_hitPoints -= effectiveDamage;
		std::cout << _name << " took " << effectiveDamage << " damage!" << std::endl;

	}
	else
		std::cout << _name << " can't take damage, it is dead." << std::endl;

}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->checkEnergyPoints())
		return (static_cast<void>(std::cout << _name << " can't be repaired, no energy point left." << std::endl));
	if (!this->checkHitPoints())
		return (static_cast<void>(std::cout << _name << " can't be repaired, it's dead already." << std::endl));
	_hitPoints += amount;
	_energyPoints--;
	std::cout << _name << " repaired itself of " << amount << " hit points." << std::endl;
}