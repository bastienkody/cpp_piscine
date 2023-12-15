#include "WrongAnimal.hpp"

/*	constructors / destructor	*/
WrongAnimal::WrongAnimal() : _type("type wronganimal")
{
	std::cout << "WrongAnimal default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal default destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type): _type(type)
{
	std::cout << "WrongAnimal param constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout << "WrongAnimal copy constructor" << std::endl;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
	{
		_type = rhs.getType();
	}
	std::cout << "WrongAnimal copy operator" << std::endl;
	return (*this);
}

/*	setter / getter	*/
std::string	WrongAnimal::getType() const { return (this->_type); }

void	WrongAnimal::setType(std::string type) { this->_type = type; }

/*	<< stream redefinition	*/
std::ostream& operator<<(std::ostream& os, const WrongAnimal &rhs)
{
	return (os << rhs.getType());
}

/*	other	*/
void	WrongAnimal::makeSound() const
{
	std::cout << "** WrongAnimal sound **" << std::endl;
}
