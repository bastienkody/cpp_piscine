#include "Zombie.hpp"

void Zombie::announce(void) const
{
	std::cout << this->_name;
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

std::string	Zombie::getName() const
{
	return (this->_name);
}

/*	def constructor	*/
Zombie::Zombie()
{
	std::cout << "\033[32mDefault constructor called for a yet unamed zombie\033[0m";
	std::cout << std::endl;
}

/*	assign constructor with init list, but I wont use here	*/
Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "\033[32mAssign constructor called for zombie " << this->_name;
	std::cout << "\033[0m" << std::endl;
}

/*	destructor	*/
Zombie::~Zombie()
{
	std::cout << "\033[31mDestructor called for zombie " << this->_name;
	std::cout << "\033[0m" << std::endl;
}