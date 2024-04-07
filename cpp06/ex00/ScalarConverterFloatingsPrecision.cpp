#include"ScalarConverter.hpp"

/*
	see _printBits and _floatprecision repo

	Floating point (double is a bigger float) number can lack of precision
	There is exactly 2^23 (8388608)	possibilities for each exponant (between 2 power of 2).
	--> for interger part, you lack of precision from 2^24 to FLOAT_MAX
	--> for decimal part (ie. from double to int), it might be 2^-24 (to be checked)

	For example : 2147483647.f
	Cannot be stored as it ; the closest is 2147483648 (+1) or 2147483520 (-127)
	The step for this range [2^31, 2^32] is actually 128.
	The float is then stored as : 2147483648.
	When we try to convert it to int, we overflow : -2147483648

	INT -> FLOAT
	I created a intFloatPreciseEnough that takes an int and states if can be 
	genuinely converted to float. (int -> float conv). It checks ranges and step
	and can provide the approximatives numbers 

	DOUBLE -> FLOAT		TO DO TODAY
	I need also need to check the lack of precision of resulting from the conv
	of a double to a float (interger + decimal pb). Not done yet

	STR -> FLOAT/DOUBLE
	I first need to check that a string nb can be stored without loss of 
	precision into a float/double : 
		- strFloatPreciseEnough()
		- strDoublePreciseEnough()
	I use sstream >> f and then sstream << f and compare the strings before and
	after conversion. 
	I must manually manage the decimal digits (sstream en donne 6 par default).
		- strNormalizeFloatings()
	I manually normalize interger part (get rid of leading whitespace and 0, 
	except the one just before the '.')
		- strNormalizeInteger()

	A single float exception was still passing (now corrected by sign bit check) : 
	2147483648.f -> stored as: 2147483648 in float
	Conv to int: -2147483648 (overflow)
	Float limits check does not work (i guess it is beause intmax cannot be
	genuinely stored as float, it sees after cast int max as it 2147483648 wich 
	directly ovflw to int min if converted?)
	No limits check pb for int/double -> char
*/

bool	ScalarConverter::intFloatPreciseEnough(int nb)
{
	if (nb <= std::pow(2, 24))
		return true;

	unsigned int	u_nb = std::abs(nb);
	double			r1 = std::pow(2, 23);
	double			r2, step;

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

bool	ScalarConverter::doubleFloatPreciseEnough(__attribute__((unused))double d)
{
	// ouais c plus dur la
	return true;
}

std::string	ScalarConverter::strNormalizeInteger(std::string src)
{
	std::string	str;
	size_t		i = 0;

	while (src[i] == '0' || isspace(src[i]))
		++i;
	if (src[i] == '.')
		str = "0";
	while (i != src.size())
		str += src[i++];
	return (str);
}

std::string	ScalarConverter::strNormalizeFloatings(std::string src, size_t floatings)
{
	std::string	str(src);
	
	while (str.size() - str.find('.') - 1 < floatings)
		str += '0';
	return (str);
}

bool	ScalarConverter::strFloatPreciseEnough(std::string str)
{
	size_t				floatings = str.size() - str.find('.') - 1;
	if (floatings == 0) ++floatings;
	std::stringstream	ss_float(str);
	float				f;
	ss_float >> f;

	std::stringstream	ss_re_float;
	ss_re_float << std::fixed << std::setprecision(floatings)  << f;

/*
	std::cout << "flotin:\t" <<  floatings << std::endl;
	std::cout << "str:\t" << strNormalizeFloatings(strNormalizeInteger(str), floatings) << std::endl;
	std::cout << "ssre:\t" << ss_re_float.str() << std::endl;
*/

	if (ss_re_float.str().compare(strNormalizeFloatings(strNormalizeInteger(str), floatings)) == 0)
		return true;
	return false;
}

bool	ScalarConverter::strDoublePreciseEnough(std::string str)
{
	size_t				floatings = str.size() - str.find('.') - 1;
	if (floatings == 0) ++floatings;
	std::stringstream	ss_double(str);
	double				d;
	ss_double >> d;

	std::stringstream	ss_re_double;
	ss_re_double << std::fixed << std::setprecision(floatings) << d;

/*
	std::cout << "flotin:\t" <<  floatings << std::endl;
	std::cout << "ssre:\t" << ss_re_double.str() << std::endl;
	std::cout << "str:\t" << strNormalizeFloatings(strNormalizeInteger(str), floatings) << std::endl;
*/

	if (ss_re_double.str().compare(strNormalizeFloatings(strNormalizeInteger(str), floatings)) == 0)
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
