#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor" << std::endl;
	_type = "type dog";
}

Dog::~Dog()
{
	std::cout << "Dog default destructor" << std::endl;
}

Dog::Dog(const std::string type) : Animal(type)
{
	std::cout << "Dog param constructor" << std::endl;
}

Dog::Dog(const Dog &src) : Animal()
{
	*this = src;
	std::cout << "Dog copy constructor" << std::endl;
}

Dog & Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog copy operator" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

/*	make sound redefinition	*/
void	Dog::makeSound() const
{
	std::cout << "** Wouff Wouff **" << std::endl;
}