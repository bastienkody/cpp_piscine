#include "Animal.hpp"

/*	constructors / destructor	*/
Animal::Animal() : _type("type animal")
{
	std::cout << "Animal default constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor" << std::endl;
}

Animal::Animal(const std::string type): _type(type)
{
	std::cout << "Animal param destructor" << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "Animal copy destructor" << std::endl;
}

Animal & Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
	{
		_type = rhs.getType();
	}
	std::cout << "Animal copy operator" << std::endl;
	return (*this);
}

/*	setter / getter	*/
std::string	Animal::getType() const { return (this->_type); }

void	Animal::setType(std::string type) { this->_type = type; }

/*	<< stream redefinition	*/
std::ostream& operator<<(std::ostream& os, const Animal &rhs)
{
	return (os << rhs.getType());
}

/*	other	*/
void	Animal::makeSound() const
{
	std::cout << "** Animal sound **" << std::endl;
}
