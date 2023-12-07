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

/*	parametric int constructor (+warning on overflow)	*/
Fixed::Fixed(const int &nb): _value(nb << _binaryPoint)
{
	std::cout << "Int constructor called" << std::endl;
	if (nb > INT_24_MAX || nb < INT_24_MIN)
		std::cout << "\033[33mWARNING : " << nb << OUT_RANGE_INT << std::endl;
}

/*	parametric float constructor
first:	shift by 8 to the left : you get an int 32bits where the 8lsb are from the fract part
second: round that to a integer : any remaining decimal from the float is discarded
third: storing in in our fixed point make the 23msb int part and 8lsb decimal! Nice
No warning for decimal rounded bc i would need std::modf (only round authorized from cmath)
*/
Fixed::Fixed(const float &nb): _value(static_cast<int>(round(nb * (1 << _binaryPoint))))
{
	std::cout << "Float constructor called" << std::endl;
	if (nb > INT_24_MAX || nb < INT_24_MIN)
		std::cout << "\033[33mWARNING : " << nb << OUT_RANGE_INT << std::endl;
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
		this->_value = rhs._value;
	return (*this);
}

/*	getter	*/
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawbits member function" << std::endl;
	return (this->_value);
}
/*	setter	*/
void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

/*	converters	*/
int		Fixed::toInt(void) const
{
	return (_value >> _binaryPoint);
}

float	Fixed::toFloat(void) const
{
 return (static_cast<float>(_value) / (1 << _binaryPoint));
}

/*	printer	*/
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

/*	overload << operator	*/
std::ostream& operator<<(std::ostream& os, const Fixed &rhs)
{
	return (os << rhs.toFloat());
}
