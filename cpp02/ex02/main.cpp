#include "Fixed.hpp"
#include <bitset>

void	print_fixed(Fixed fixed, std::string name)
{
	std::cout << name << " : " << fixed << " ; as an int : " << fixed.toInt() << std::endl;
	fixed.printRawBits();
	std::cout << "----------------------------" << std::endl;
}

void	call_print(Fixed a, Fixed b, Fixed c, Fixed d)
{
	print_fixed(a, "a");
	print_fixed(b, "b");
	print_fixed(c, "c");
	print_fixed(d, "d");
}

int	main(void)
{
{
	std::cout << "\033[4m42 main example:\033[0m" << std::endl;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}
{
	std::cout << "\033[4mCustom main example:\033[0m" << std::endl;

	Fixed	a(2000000);
	Fixed	b(2000001);
	Fixed	c(52.75f);
	Fixed	d(41.3f);

	call_print(a, b, c, d);

	std::cout << "\033[32mIncrement all\033[m" << std::endl;
	{a++; b++; c++; d++;}
	call_print(a, b, c, d);

	
	std::cout << "\033[32mDecrement all\033[m" << std::endl;
	{a--; b--; c--; d--;}
	call_print(a, b, c, d);

	std::cout << "\033[32ma = a + b ; c = c - d\033[m" << std::endl;
	{a = a + b; c = c - d;}
	call_print(a, b, c, d);

	std::cout << "\033[32mb = a / b + 9 ; d = c * 1.5\033[m" << std::endl;
	{b = a / b + 9; d = c * 1.5f;}
	call_print(a, b, c, d);

	std::cout << "\033[32mmax(b, c) : \033[m" << Fixed::max(b, c) << std::endl;
	std::cout << "\033[32mmin(const b, const c) : \033[m" << Fixed::min((const Fixed)b, (const Fixed)c) << std::endl;

}
}
