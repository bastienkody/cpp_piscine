#include "Weapon.hpp"

/*	def constructor	*/
Weapon::Weapon()
{
	std::cout << "\033[32mWeapon: default constructor\033[0m" << std::endl;
}

/*	param constructor	*/
Weapon::Weapon(std::string type): _type(type)
{
	std::cout << "\033[32mWeapon: parametized constructor called with type ";
	std::cout << this->_type << "\033[0m" <<std::endl;
}

/*	destructor	*/
Weapon::~Weapon()
{
	std::cout << "\033[31mWeapon: default destructor of type ";
	std::cout << this->_type <<  "\033[0m" << std::endl;
}

/*	getter	*/
const std::string	&Weapon::getType() const {return (this->_type);}

/*	setter	*/
void	Weapon::setType(std::string type) {this->_type = type;}
