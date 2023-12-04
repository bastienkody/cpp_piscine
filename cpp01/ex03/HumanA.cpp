#include "HumanA.hpp"

/*	no default constructor (most prob forbidden)	*/

/*	assign constructor	*/
HumanA::HumanA(std::string name, Weapon &weapon):_name(name),_weapon(weapon)
{
	std::cout << "\033[32mHumanA: assign constructor for ";
	std::cout << this->_name << " with weapon ";
	std::cout << _weapon.getType() << "\033[0m" << std::endl;
}

/*	destructor	*/
HumanA::~HumanA()
{
	std::cout << "\033[31mHumanA: default destructor\033[0m" << std::endl;
}

/*	other	*/
void	HumanA::attack() const
{
	std::cout << this->_name << " attacks with their ";
	std::cout << this->_weapon.getType() << std::endl;
}