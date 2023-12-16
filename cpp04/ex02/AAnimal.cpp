#include "AAnimal.hpp"

/*	constructors / destructor	*/
AAnimal::AAnimal() : _type("type animal")
{
	std::cout << "AAnimal default constructor" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal default destructor" << std::endl;
}

AAnimal::AAnimal(const std::string type): _type(type)
{
	std::cout << "AAnimal param destructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	*this = src;
	std::cout << "AAnimal copy destructor" << std::endl;
}

AAnimal & AAnimal::operator=(const AAnimal &rhs)
{
	if (this != &rhs)
	{
		_type = rhs.getType();
	}
	std::cout << "AAnimal copy operator" << std::endl;
	return (*this);
}

/*	setter / getter	*/
std::string	AAnimal::getType() const { return (this->_type); }

void	AAnimal::setType(std::string type) { this->_type = type; }

/*	<< stream redefinition	*/
std::ostream& operator<<(std::ostream& os, const AAnimal &rhs)
{
	return (os << rhs.getType());
}

/*	other	*/
Brain	*AAnimal::getBrain() const
{
	return (NULL);
}
