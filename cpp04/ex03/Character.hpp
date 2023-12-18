#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <cstdlib>
#include "ICharacter.hpp"

#define MAX_SLOTS 4

class Character : public ICharacter
{
	private:
		std::string		_name;
		AMateria		*_inventory[4];
	public:
		Character();
		~Character();
		Character(const std::string name);
		Character(const Character &src);
		Character & operator=(const Character &rhs);
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif
