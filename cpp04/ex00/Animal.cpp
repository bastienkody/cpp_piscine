#include "Animal.hpp"

/*	constructors / destructor	*/
Animal::Animal()
{
	_type = "";
	std::cout << "Animal default constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal param constructor" << std::endl;
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
std::string	Animal::getType() const
{
	return (this->_type);
}

void		Animal::setType(std::string type)
{
	this->_type = type;
}

/*	other	*/
void	Animal::makeSound()
{
	std::cout << "** Animal sound **" << std::endl;
}
