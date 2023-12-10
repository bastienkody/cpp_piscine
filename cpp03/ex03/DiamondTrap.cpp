#include "DiamondTrap.hpp"

DiamondTrap::~DiamondTrap()
{
	std::cout << "Diamond Destructor" << std::endl;
}

/*	redefining data member by selecting from parents classes */
DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "Diamond Default constructor" << std::endl;
}

//	1 - The order of constr calls is important : base class must always be first
//	2 - changing the param of Clap constr in order to have a different Clap name
//	This also update Frag and Scav names, bc they both inherits from Clap name, 
//	they do not declare a _name member data in their .h so their name is exactly
//	Clap's one ; vs Diamond that redeclares (and redefines) it own _name, and 
//	can also access Clap name. 
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "Diamond Parametric constructor" << std::endl;
}

/*	specific _name attribute copy needed	*/
DiamondTrap::DiamondTrap(DiamondTrap &src) : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	_name = src._name;
	std::cout << "Diamond Copy constructor" << std::endl;
}

/*	I only call Clap copy operator.	*/
DiamondTrap & DiamondTrap::operator=(DiamondTrap &rhs)
{
	ClapTrap::operator=(rhs);
	_name = rhs._name;
	std::cout << "Diamond Copy operator" << std::endl;
	return (*this);			
}

/*	~= choosing attack from Scav and not Frag or Clap by explicitly calling it	*/
/*	Is there a better way ? */
void DiamondTrap::attack(const std::string & target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My Diamond name is " << _name;
	std::cout << " and my Clap name is " << ClapTrap::_name << std::endl;
	//std::cout << " and my Frag name is " << FragTrap::_name << std::endl;
	//std::cout << " and my Scav name is " << ScavTrap::_name << std::endl;
}