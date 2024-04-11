#include "Character.hpp"

// def
Character::Character()
{
	for (int i = 0; i < MAX_SLOTS; ++i)
		_inventory[i] = NULL;
}

// destructor
Character::~Character()
{
	for (int i = 0; i < MAX_SLOTS; ++i)
		if (_inventory[i])
			delete _inventory[i]; 
}

// param
Character::Character(const std::string name) : _name(name)
{
	for (int i = 0; i < MAX_SLOTS; ++i)
		_inventory[i] = NULL;
}

/*	
	Mod post ehcange zara : pour les copies d'inventory, il faut check les NULL, 
	car clone() appelle new sur une materia, et celle si est NULL : segfault.
*/

// copy (deep on slots)
Character::Character(const Character &src)
{
	_name = src._name;

	for (int i = 0; i < MAX_SLOTS; ++i)
	{
		if (src._inventory[i] == NULL)
			_inventory[i] = NULL;
		else
			_inventory[i] = src._inventory[i]->clone();	// clone them
	}
}

// copy operator (deep on slots)
Character & Character::operator=(const Character &rhs)
{
	this->_name = rhs.getName();				// name
	for (int i = 0; i < MAX_SLOTS; ++i)
		if (_inventory[i])
			delete _inventory[i];				// free own inventory
	for (int i = 0; i < MAX_SLOTS; ++i)
	{
		if (rhs._inventory[i] == NULL)
			_inventory[i] = NULL;
		else
			_inventory[i] = rhs._inventory[i]->clone();	// clone them
	}
	return (*this);
}

// getter
std::string const & Character::getName() const
{
	return (_name);
}

// definition of equip Materia
void Character::equip(AMateria* m)
{
	if (m == NULL)
		return (static_cast<void>(std::cout << "Materia to equip cant be null" << std::endl));
	int i = 0;
	for (; i < MAX_SLOTS + 1; ++i)
		if (!_inventory[i])
			break;
	if (i > 3)
		return ;		// subject does not want : std::cout << "Inventory full" << std::endl
	_inventory[i] = m;
}

// unequip : must delete Materia in main + no print error (cf. subject)
void Character::unequip(int idx)
{
	if (idx < 0 || ! _inventory[idx])
		return ;
	_inventory [idx] = NULL;
}

// use ; subject does not want : std::cout << "Bad index" << std::endl;
void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || ! _inventory[idx])
		return ;
	_inventory[idx]->use(target);
}
