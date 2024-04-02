#include"ScalarConverter.hpp"

//	Default constructor
ScalarConverter::ScalarConverter() {}

//	Default destructor
ScalarConverter::~ScalarConverter() {}

//	Copy constructor (via copy operator)
ScalarConverter::ScalarConverter(const ScalarConverter & src) {*this = src;}

//	Copy operator
ScalarConverter & ScalarConverter::operator=(const ScalarConverter & rhs) {return (*this);}

/* Convert (FULL PARSING, c-ish style, unfinished but almost, not tested)
void ScalarConverter::convertFullParsing(std::string lit)
{
	if (lit.empty())
		std::cerr << "EMPTY ARG" << std::endl;
	else if (lit.size() == 1)
	{
		if (isdigit(lit.front()))
			std::cout << "INT" << std::endl;
		else if (isprint(lit.front()))
			std::cout << "CHAR" << std::endl;
		else
			std::cout << "BAD ARG (char not printable)" << std::endl;
	}
	else // several char
	{
		if (!lit.compare("-inff") || !lit.compare("+inff"))
			std::cout << "FLOAT" << std::endl;
		else if (!lit.compare("-inf") || !lit.compare("+inf") || !lit.compare("nan"))
			std::cout << "DOUBLE" << std::endl;
		else if (isStringOnly(lit, 0, &isdigit) || (lit.front() == '-' && isStringOnly(lit, 1, &isdigit)))
		{
			if (int_overflow)
				std::cout << "BAD ARG (int overflow)" << std::endl;
			else
				std::cout << "INT" << std::endl;
		}
		else if (std::string::size_type point_pos = lit.find('.') != std::string::npos) // on a trouve un point
		{
			if (point_pos == lit.front() || point_pos == lit.back())
				std::cout << "BAD ARG (point at first or last char)" << std::endl;
			else if (lit.front() == '-' || isdigit(lit.front()) && isdigit(lit_all except begin, end, point_pos))
			{
				if (lit.back() == 'f')
					std::cout << "FLOAT" << std::endl;
				else if (isdigit(lit.back()))
					std::cout << "DOUBLE" << std::endl;
				else
					std::cout << "BAD ARG" << std::endl;
			}
		}
		else
			std::cout << "BAD ARG" << std::endl;
	}
}

// Apply is*(char/int) functions to a full string (ie. full str isdigit)
// flag offset bc i did not find a way to do a str + 1 as in C
bool	ScalarConverter::isStringOnly(std::string str, size_t offset, int(*fct)(int))
{
	for (std::string::iterator it = str.begin() + offset; it != str.end(); ++it)
		if (!fct(*it))
			return false;
	return true;
}
*/

// Convert (mix sstream and parsing)
void ScalarConverter::convert(std::string lit)
{
	if (lit.empty())
		std::cerr << "EMPTY ARG" << std::endl;
	else if (lit.size() == 1 && !isdigit(lit[0]) && isprint(lit[0])) 
		std::cout << "CHAR" << std::endl;
	else if (!lit.compare("-inff") || !lit.compare("+inff"))
		std::cout << "FLOAT" << std::endl;
	else if (!lit.compare("-inf") || !lit.compare("+inf") || !lit.compare("nan"))
		std::cout << "DOUBLE" << std::endl;
	else if (lit.find('.'))
	{
		if (lit.back() == 'f' && isFloat(lit))
			std::cout << "FLOAT" << std::endl;
		else if (lit.back() != 'f' && isDouble(lit))
			std::cout << "DOUBLE" << std::endl;
	}
	else if (isInt(lit))
		std::cout << "INT" << std::endl;
	else
		std::cerr << "BAD ARG" << std::endl;
}

// FLOAT : need to remove trailing f for sstream conversion
bool	ScalarConverter::isFloat(std::string lit)
{
	std::string	litTrailingFRemoved;
	for (int i = 0; i < lit.size() - 1; ++i)
		litTrailingFRemoved += lit[i];

	std::stringstream	ss_float(litTrailingFRemoved);
	float				f;

	ss_float >> f;
	if (!ss_float.fail() && ss_float.eof())
		return true;
	return false;
}

// DOUBLE : overflows handled (giga big), but not loose of precision ...
bool	ScalarConverter::isDouble(std::string lit)
{
	std::stringstream	ss_double(lit);
	double				d;

	ss_double >> d;
	if (!ss_double.fail() && ss_double.eof())
		return true;
	return false;
}

// INT : overflows handled
bool	ScalarConverter::isInt(std::string lit)
{
	std::stringstream	ss_int(lit);
	int					i;

	ss_int >> i;
	if (!ss_int.fail() && ss_int.eof())
		return true;
	return false;
}