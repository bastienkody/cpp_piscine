#include"ScalarConverter.hpp"

/*
	see _printBits repo

	Floating point (double is just a double float) number can lack of precision
	There is exactly 2^23 (8388608)	possibilities for each exponant (between 2 power of 2).
	--> for interger part, you lack of precision from 2^24 to FLOAT_MAX
	--> for decimal part (ie. from double to int), it might be 2^-24 (to be checked)

	For example : 2147483647.f
	Cannot be stored as it ; the closest is 2147483648 (+1) or 2147483520 (-127)
	The step for this range [2^31, 2^32] is actually 128.
	The float is then stored as : 2147483648.
	When we try to convert it to int, we overflow : -2147483648

	I created a intFloatPreciseEnough that takes an int and states if can be 
	genuinely converted to float.
	The problem : it takes an int as parameter, but in my program i only have
	the lfoat representation, and the stirng. 
	I can try to atoi(string) but I might protect overflow
	I can use sstream on the string? Removing the . and the f and not checking
	eofbit since i know it has already been accepted as a float. I must manage 
	+inff/-inff/nanf too. 

	Also I need a function to check the lack of precision of decimal (+integer?)
	from double to float. 

	I might also be checking that when I convert from string to float because : 
	1 - 134217729.f 
		float -> 134217728.f
		double -> 134217729.f
	The double would have been able to store it ... however i must first convert
	to real typer, and then from it to other, not from str.
	2 - -2147483649.f
		int		->	-2147483648
		float	->	-2147483648.f
		double	->	-2147483648.
	Is it true or not? Float stored an approximation, and when returned to a
	type can have it genuinely stored, has the wrong data.
	--> Definitely I must check the precision when using sstream to get to the
	real type. This way I can stop unprecise matter later. Plus it seems ok
	to refuse to store a number you can't get precisely. 
	This matter is also true with decimal. 
	--> test of sstring >> float in a new repo for now.


*/

bool	ScalarConverter::intFloatPreciseEnough(int nb)
{
	unsigned int	u_nb = std::abs(nb);

	if (nb <= std::pow(2, 24))
		return true;

	double	r1 = std::pow(2, 23);
	double	r2;
	double	step;

	while (r1 * 2 < static_cast<double>(u_nb))
		r1 *= 2;
	r2 = r1 *2;
	step = (r2 - r1) / std::pow(2, 23);

	while (r1 < static_cast<double>(u_nb))
		r1 += step;

	if (r1 == static_cast<double>(u_nb))
		return true;
	return false;
}

void	ScalarConverter::printFloatBits(__attribute__((unused)) const float & f) 
{
	size_t				len = sizeof(f) * 8;
	const unsigned char	*raw = reinterpret_cast<const unsigned char *>(&f);

	std::cout << "float: " << std::fixed << std::left << std::setw(15) << f << ":\t";
	for (int i = static_cast<int>(len) - 1; i >= 0; --i)
	{
		std::cout << (((raw[i / 8]) >> (i % 8)) & 1);
		if (i == static_cast<int>(len) -1 || i == static_cast<int>(len) -1 - 8)
			std::cout << '.';
	}
	std::cout << std::endl;
}

void	ScalarConverter::printDoubleBits(__attribute__((unused)) const double & d)
{
	size_t				len = sizeof(d) * 8;
	const unsigned char	*raw = reinterpret_cast<const unsigned char *>(&d);

	std::cout << "double: " << std::fixed << std::left << std::setw(30) << d << ":\t";
	for (int i = static_cast<int>(len) - 1; i >= 0; --i)
	{
		std::cout << (((raw[i / 8]) >> (i % 8)) & 1);
		if (i == static_cast<int>(len) -1 || i == static_cast<int>(len) -1 - 11)
			std::cout << '.';
	}
	std::cout << std::endl;
}

void	ScalarConverter::printIntBits(__attribute__((unused)) const int & i)
{
	size_t	len = sizeof(i) * 8;

	std::cout << "int: " << std::left << std::setw(13) << i << ":\t";
	for (int j = static_cast<int>(len) - 1; j >= 0; --j)
	{
		std::cout << ((i >> j) & 1);
		if (j == static_cast<int>(len) - 1)
			std::cout << '.';
	}
	std::cout << std::endl;
}

void	ScalarConverter::printCharBits(__attribute__((unused))const char & c)
{
	size_t	len = sizeof(c) * 8;

	std::cout << "char: " << std::left << std::setw(5) << static_cast<int>(c) << ":\t";
	for (int i = static_cast<int>(len) - 1; i >= 0; --i)
	{
		std::cout << ((c >> i) & 1);
		if (i == static_cast<int>(len) - 1)
			std::cout << '.';
	}
	std::cout << std::endl;
}
