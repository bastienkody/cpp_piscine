#include "ScavTrap.hpp"

//	Constructors of DERIVED class automatically call PARENT ones
//	using overload : copy, param and default are nicely selected
//	However, its more obvious to WRITE it down in the initialisation list,
//	(where you might also put specific data assignement for the derived class)
//	but NEVER in the body : it creates a new object!!!!
//	For operator definition (and maybe any other memb function?), you can't
//	have it in init list, you need to put it in the body

ScavTrap::~ScavTrap()
{
	std::cout << "Scav Destructor" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	_name = ""; 		// this is not needed bc ClapTrap does it already
	_hitPoints = 100;	// this is needed bc ClapTrap set it a 10
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
	// Note that if I let "*this = src", the copy would have happened twice !
	std::cout << "Scav Copy constructor" << std::endl;
}

/*	Copy operator (cant be in init list)	*/
ScavTrap & ScavTrap::operator=(ScavTrap &rhs)
{
	ClapTrap::operator=(rhs); 
// calling the parent definition of an operator (class scope needed)
// seems like no pb with the return of ClapTrap::operator=, above code is read
	std::cout << "Scav Copy operator" << std::endl;
	return (*this);			
}

/*	redefinition of attack : this one will be selected over the parent ones	*/
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

/*	scavtrap special fct	*/
void	ScavTrap::guarGate() const
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}