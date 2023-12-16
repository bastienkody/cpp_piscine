#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor" << std::endl;
	_type = "type dog";
	_brain = new Brain;
}

Dog::~Dog()
{
	std::cout << "Dog default destructor" << std::endl;
	delete	_brain;
}

Dog::Dog(const std::string type) : Animal(type)
{
	std::cout << "Dog param constructor" << std::endl;
	_brain = new Brain;
}

Dog::Dog(const Dog &src) : Animal()
{
	std::cout << "Dog copy constructor" << std::endl;
	_type = src.getType();
	_brain = new Brain;			// alloc for deep copy using default constructor	
	*_brain = *(src._brain);	// value copy using Brain::operator=
}

Dog & Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog copy operator" << std::endl;
	if (this != &rhs)
	{
		_type = rhs.getType();
		delete _brain;
		_brain = new Brain;				// alloc for deep copy
		*(_brain) = *(rhs._brain);		// value copy using Brain::operator=
	}
	return (*this);
}

/*	make sound redefinition	*/
void	Dog::makeSound() const
{
	std::cout << "** Wouff Wouff **" << std::endl;
}

/*	getter on _brain	*/
Brain	*Dog::getBrain() const
{
	return (_brain);
}
