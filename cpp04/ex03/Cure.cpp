#include "Cure.hpp"

// def
Cure::Cure() : AMateria()
{
	_type = "cure";
}

// copy
Cure::Cure(const Cure &src) : AMateria(src)
{;}

// copy operator
Cure & Cure::operator=(const Cure & rhs)
{
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

//	heap allocate here to return a usuable object
AMateria*	Cure::clone() const
{
	try
	{
		return (new Cure(*this));
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " in Cure::clone" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

void 		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
