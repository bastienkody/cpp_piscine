#include "AMateria.hpp"

// default
AMateria::AMateria()
{
	_type = "";
}
// compile error if no definition
AMateria::~AMateria()
{

}

// param
AMateria::AMateria(std::string const & type)
{
	_type = type;
}

// copy
AMateria::AMateria(const AMateria &src)
{
	_type = src.getType();
}

// copy operator
AMateria & AMateria::operator=(const AMateria &rhs)
{
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

// getter
std::string const & AMateria::getType() const { return (_type); }

// compile error if no definition
void AMateria::use(ICharacter& target)
{
	(void)target;
}