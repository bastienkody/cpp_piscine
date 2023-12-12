#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat default constructor" << std::endl;
	_type = "type wrong cat";
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat default destructor" << std::endl;
}

WrongCat::WrongCat(const std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat param constructor" << std::endl;
	_type = type;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal()
{
	*this = src;
	std::cout << "WrongCat copy constructor" << std::endl;
}

WrongCat & WrongCat::operator=(const WrongCat &rhs)
{
	std::cout << "WrongCat copy operator" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

/*	make sound redefinition	*/
void	WrongCat::makeSound() const
{
	std::cout << "** Miaou Miaou **" << std::endl;
}