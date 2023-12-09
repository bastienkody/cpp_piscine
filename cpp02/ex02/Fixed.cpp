#include "Fixed.hpp"

const int	Fixed::_binaryPoint = 8;

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int &nb): _value(nb << _binaryPoint)
{
	if (nb > INT_24_MAX || nb < INT_24_MIN)
		std::cout << "\033[33mWARNING : " << nb << OUT_RANGE_INT << std::endl;
}

Fixed::Fixed(const float &nb): _value(static_cast<int>(round(nb * (1 << _binaryPoint))))
{
	if (nb > INT_24_MAX || nb < INT_24_MIN)
		std::cout << "\033[33mWARNING : " << nb << OUT_RANGE_INT << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed & Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		this->_value = rhs._value;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

int		Fixed::toInt(void) const
{
	return (_value >> _binaryPoint);
}

float	Fixed::toFloat(void) const
{
 return (static_cast<float>(_value) / (1 << _binaryPoint));
}

void	Fixed::printRawBits(void) const
{
	std::cout << "Binary form (msb left) : ";
	for (int i = 31; i >= 0; i--)
	{
		if (i == 7)
			std::cout << '.';
		std::cout << (_value >> i & 1);
	}
	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed &rhs)
{
	return (os << rhs.toFloat());
}

/*	comparison operators	*/
bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs)  const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

/*	maths operators	*/
Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return (this->getRawBits() + rhs.getRawBits());
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return (this->getRawBits() - rhs.getRawBits());
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	if (rhs._value == 0)
		std::cout << "Warning : division by zero is about to happen" << std::endl;
	return (this->toFloat() / rhs.toFloat());
}

/*	increment operators (postfixe overload via a int dummy)	*/
Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	this->_value++;
	return (tmp);
}

Fixed &	Fixed::operator++()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	this->_value--;
	return (tmp);
}

Fixed &	Fixed::operator--()
{
	this->_value--;
	return (*this);
}

/*	min / max */
Fixed&	Fixed::min(Fixed& a, Fixed& b) const
{
	return ((a < b) ? a : b);
}

Fixed const&	Fixed::min(Fixed const& a, Fixed const& b) const
{
	return ((a < b) ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) const
{
	return ((a < b) ? b : a);
}

Fixed const&	Fixed::max(Fixed const& a, Fixed const& b) const
{
	return ((a < b) ? b : a);
}