#include "Dog.hpp"
#include "AAnimal.hpp"

Dog::Dog() : AAnimal()
{
	std::cout << "Dog default constructor" << std::endl;
	_type = "type dog";
	try
	{
		_brain = new Brain;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " in Dog def constructor" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

Dog::~Dog()
{
	std::cout << "Dog default destructor" << std::endl;
	delete	_brain;
}

Dog::Dog(const std::string type) : AAnimal(type)
{
	std::cout << "Dog param constructor" << std::endl;
	try
	{
		_brain = new Brain;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " in Dog param constructor" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

Dog::Dog(const Dog &src) : AAnimal()
{
	std::cout << "Dog copy constructor" << std::endl;
	_type = src.getType();
	try
	{
		_brain = new Brain;			// alloc for deep copy using default constructor	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " in Dog copy constructor" << std::endl;
		std::exit(EXIT_FAILURE);
	}	
	*_brain = *(src._brain);	// value copy using Brain::operator=
}

Dog & Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog copy operator" << std::endl;
	if (this != &rhs)
	{
		_type = rhs.getType();
		delete _brain;
		try
		{
			_brain = new Brain;				// alloc for deep copy
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " in Dog copy operator" << std::endl;
			std::exit(EXIT_FAILURE);
		}
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
