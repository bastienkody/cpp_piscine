#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Cat default constructor" << std::endl;
	_type = "type cat";
	_brain = new Brain;
}

Cat::~Cat(void)
{
	std::cout << "Cat default destructor" << std::endl;
	delete _brain;
}

Cat::Cat(const std::string type) : Animal(type)
{
	std::cout << "Cat param constructor" << std::endl;
	_brain = new Brain;
}

Cat::Cat(const Cat &src) : Animal()
{
	std::cout << "Cat copy constructor" << std::endl;
	_type = src.getType();
	_brain = new Brain(*src.getBrain());	// alloc for deep copy	+ use of copy construct
}

Cat & Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat copy operator" << std::endl;
	if (this != &rhs)
	{
		_type = rhs.getType();
		delete _brain; 
		_brain = new Brain(*rhs.getBrain());	
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
