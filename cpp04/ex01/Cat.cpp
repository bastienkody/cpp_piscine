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
}

Cat::Cat(const std::string type) : Animal(type)
{
	std::cout << "Cat param constructor" << std::endl;
}

Cat::Cat(const Cat &src) : Animal()
{
	*this = src;
	std::cout << "Cat copy constructor" << std::endl;
}

Cat & Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat copy operator" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

/*	make sound redefinition	*/
void	Cat::makeSound() const
{
	std::cout << "** Miaou Miaou **" << std::endl;
}
