#include "Fixed.hpp"

const int	Fixed::_binaryPoint = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Default destructor called" << std::endl;
}

/*	copy (using copy assignement)	*/
Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/*	copy assignment	*/
Fixed & Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignement operator" << std::endl;
	if (this != &rhs)
		this->setRawBits(rhs.getRawBits());
	return (*this);
}

/*	getter setters	*/
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawbits member function" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) {this->_value = raw;}
