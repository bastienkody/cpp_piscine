#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string			_type;
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		void				setType(std::string type);
		const std::string	&getType() const;
};

#endif