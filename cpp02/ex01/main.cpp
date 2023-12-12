#include "Fixed.hpp"

int	main(void)
{
{
	std::cout << "\033[4m42 main example:\033[0m" << std::endl;

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}
{
	std::cout << "\033[4mCustom main example:\033[0m" << std::endl;

	Fixed	a(-215);
	Fixed	b(3.5f);
	Fixed	c(INT_24_MAX);
	Fixed	d(INT_24_MIN);
	Fixed	e(INT_24_MAX + 1);
	Fixed	f(INT_24_MIN - 1);

	std::cout << "a :" << -215 << std::endl;
	a.printRawBits();
	std::cout << "via overload << :\t" << a << std::endl;
	std::cout << "via .toInt() :\t\t" << a.toInt() << std::endl;

	std::cout << "b :" << 3.5f << std::endl;
	b.printRawBits();
	std::cout << "via overload << :\t" << b << std::endl;
	std::cout << "via .toInt() :\t\t"  << b.toInt() << std::endl;

	std::cout << "c :" << INT_24_MAX << std::endl;
	c.printRawBits();
	std::cout << "via overload << :\t" << c << std::endl;
	std::cout << "via .toInt() :\t\t"  << c.toInt() << std::endl;

	std::cout << "d :" << INT_24_MIN << std::endl;
	d.printRawBits();
	std::cout << "via overload << :\t" << d << std::endl;
	std::cout << "via .toInt() :\t\t"  << d.toInt() << std::endl;

	std::cout <<  "e :" << INT_24_MAX + 1 << std::endl;
	e.printRawBits();
	std::cout << "via overload << :\t" << e << std::endl;
	std::cout << "via .toInt() :\t\t"  << e.toInt() << std::endl;

	std::cout << "f :" << INT_24_MIN - 1 << std::endl;
	f.printRawBits();
	std::cout << "via overload << :\t" << f << std::endl;
	std::cout << "via .toInt() :\t\t"  << f.toInt() << std::endl;
}
}
