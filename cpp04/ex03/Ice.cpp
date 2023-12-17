#include "Ice.hpp"

// def
Ice::Ice() : AMateria()
{
	_type = "ice";
}

// copy
Ice::Ice(const Ice &src) : AMateria(src)
{;}

// copy operator
Ice & Ice::operator=(const Ice & rhs)
{
	if (this != &rhs)
		_type = rhs.getType(); // why not copying the type??
	return (*this);
}

//	heap allocate here to return a usuable object
AMateria*	Ice::clone() const
{
	try
	{
		return (new Ice(*this));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " in Ice::clone" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void 		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}