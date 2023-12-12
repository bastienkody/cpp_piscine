#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

/*	custom limits*/
#define INT_24_MAX 8388607
#define INT_24_MIN -8388608

/*	err msg	*/
#define OUT_RANGE_INT " : overflow detected, might lead to data corruption.\n\
Note that integer part for fixed point is on 23bits: [-8388608 to 8388607]\033[0m"

class Fixed
{
	private:
		int					_value;
		static const int	_binaryPoint;
	public:
		Fixed();
		~Fixed();
		Fixed(const int &nb);
		Fixed(const float &nb);
		Fixed(const Fixed &src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		void	printRawBits(void) const;
		int		toInt(void) const;
		float	toFloat(void) const;
		Fixed &	operator=(const Fixed &rhs);
		Fixed	operator+(const Fixed &rhs) const;
		Fixed	operator-(const Fixed &rhs) const;
		Fixed	operator*(const Fixed &rhs) const;
		Fixed	operator/(const Fixed &rhs) const;
		bool	operator>(const Fixed &rhs) const;
		bool	operator>=(const Fixed &rhs) const;
		bool	operator<(const Fixed &rhs) const;
		bool	operator<=(const Fixed &rhs) const;
		bool	operator==(const Fixed &rhs) const;
		bool	operator!=(const Fixed &rhs) const;
		Fixed	operator++(int);
		Fixed &	operator++();
		Fixed	operator--(int);
		Fixed &	operator--();
		static Fixed&			min(Fixed& a, Fixed& b);
		static Fixed const&	min(Fixed const& a, Fixed const& b);
		static Fixed &			max(Fixed& a, Fixed& b);
		static Fixed const &	max(Fixed const& a, Fixed const& b);
		};

/*	outside*/
std::ostream& operator<<(std::ostream& os, const Fixed &rhs);

#endif
