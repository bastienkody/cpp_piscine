#include "HumanB.hpp"

/*	param constructor	*/
HumanB::HumanB(std::string name):_name(name)
{
	std::cout << "\033[32mHumanB: parametized constructor for ";
	std::cout << this->_name << " with no weapon yet" << "\033[0m" << std::endl;
}

/*	destructor	*/
HumanB::~HumanB()
{
	std::cout << "\033[31mHumanB: default destructor\033[0m" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {this->_weapon = &weapon;}

void	HumanB::attack() const
{
	std::cout << this->_name << " attacks with their ";
	std::cout << this->_weapon->getType() << std::endl;
}
