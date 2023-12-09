#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &src);
		ClapTrap & operator=(ClapTrap &rhs);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	fullDisplay() const;
		std::string		getName() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;
		void			setName(std::string name);
		void			setHitPoints(unsigned int hp);
		void			setEnergyPoints(unsigned int eng);
		void			setAttackDamage(unsigned int att);
	private:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
		bool			checkHitPoints() const;
		bool			checkEnergyPoints() const;

};

#endif