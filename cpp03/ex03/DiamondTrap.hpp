#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

//	DiamondTrap inherits from both derived classes of ClapTrap
//				  Clap
//				/	   \
//			   /		\
//			Frag		 Scav
//			  \			 /
//			   \		/
//				 Diamond
//
//	How to select attributes wether from Frag, Scav or Clap?
//	--> data and functions, done via scope operator inside the body definition
//	of Diamond member function (see attack() and constructors)

//	How to instanciate only once Clap for both Frag and Scav?
//	--> by specifiyng virtual inheritance of Clap for derived Frag and Scav.
//	c++ deals it by itself then. 

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap &src);
		DiamondTrap & operator=(DiamondTrap &rhs);
		void	whoAmI();
		void	attack(const std::string & target);
};

#endif