#include "Cat.hpp"
#include "AAnimal.hpp"

Cat::Cat(void) : AAnimal()
{
	std::cout << "Cat default constructor" << std::endl;
	_type = "type cat";
	try
	{
		_brain = new Brain;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " in Cat def constructor" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

Cat::~Cat(void)
{
	std::cout << "Cat default destructor" << std::endl;
	delete _brain;
}

Cat::Cat(const std::string type) : AAnimal(type)
{
	std::cout << "Cat param constructor" << std::endl;
	try
	{
		_brain = new Brain;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " in Cat param constructor" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

Cat::Cat(const Cat &src) : AAnimal()
{
	std::cout << "Cat copy constructor" << std::endl;
	_type = src.getType();
	try
	{
		_brain = new Brain(*src.getBrain());	// alloc for deep copy	+ use of copy construct
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " in Cat copy constructor" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

Cat & Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat copy operator" << std::endl;
	if (this != &rhs)
	{
		_type = rhs.getType();
		delete _brain;
		try
		{
			_brain = new Brain(*rhs.getBrain());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << " in Cat copy operator" << std::endl;
			std::exit(EXIT_FAILURE);
		}
	}
	return (*this);
}

/*	make sound redefinition	*/
void	Cat::makeSound() const
{
	std::cout << "** Miaou Miaou **" << std::endl;
}

/*	getter on _brain	*/
Brain	*Cat::getBrain() const
{
	return (_brain);
}
