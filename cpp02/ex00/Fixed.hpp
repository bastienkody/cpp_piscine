#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_binaryPoint;
	public:
		Fixed();
		~Fixed();
		Fixed(const int &nb);
		Fixed(const Fixed &src);
		Fixed & operator=(const Fixed &rhs);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};

#endif