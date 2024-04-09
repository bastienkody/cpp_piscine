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
		it also need to check if there is a leading sign

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
	//std::cout << "under:" << r1 - step << " upper:" << r1 << std::endl;
	return false;
}

std::string	ScalarConverter::strNormalizeInteger(std::string src)
{
	std::string	str;
	size_t		i = 0;

	while (src[i] == '0' || isspace(src[i]))
		++i;
	if (src[i] == '-')
		str = src[i++];
	if (src[i] == '+')
		i++;			// leading '+' is discarded, not leading '-'
	if (src[i] == '.')
		str += "0";
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

	//std::cout << "str normalized:" << strNormalizeFloatings(strNormalizeInteger(str), floatings);

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

	//std::cout << "str normalized:" << strNormalizeFloatings(strNormalizeInteger(str), floatings);

	if (ss_re_double.str().compare(strNormalizeFloatings(strNormalizeInteger(str), floatings)) == 0)
		return true;
	return false;
}
