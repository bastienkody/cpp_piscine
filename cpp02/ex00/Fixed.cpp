#include "Fixed.hpp"

/*	static init	*/
const int	Fixed::_binaryPoint = 8;

/*	default	*/
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

/*	other constructors	*/
Fixed::Fixed(const int &nb)
{
	std::cout << "Parametric constructor called" << std::endl;
	this->_value = nb;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	if (this != &src)
		*this = src;
}

Fixed & Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignement operator" << std::endl;
	if (this != &rhs)
	{
		this->_value = rhs._value;
		this->setRawBits(rhs.getRawBits());
	}
	return (*this);
}

/*	getter setters	*/
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawbits member function" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
