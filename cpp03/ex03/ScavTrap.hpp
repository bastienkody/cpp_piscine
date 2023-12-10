#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &src);
		ScavTrap & operator=(ScavTrap &rhs);
		void	attack(const std::string& target);
		void	guardGate() const;
};

#endif