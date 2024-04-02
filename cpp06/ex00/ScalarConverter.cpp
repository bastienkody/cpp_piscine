#include"ScalarConverter.hpp"

//	Unusable cons/des - tructors
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter & src) {*this = src;}
ScalarConverter & ScalarConverter::operator=(__attribute__((unused)) const ScalarConverter & rhs) {return (*this);}

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
DataType ScalarConverter::convert(std::string lit)
{
	if (lit.size() == 1 && !isdigit(lit[0]) && isprint(lit[0])) 
		return CHAR;
	else if (!lit.compare("-inff") || !lit.compare("+inff")|| !lit.compare("nanf"))
		return FLOAT;
	else if (!lit.compare("-inf") || !lit.compare("+inf") || !lit.compare("nan"))
		return DOUBLE;
	else if (lit.find('.') != std::string::npos)
	{
		if (lit.back() == 'f' && isFloat(lit))
			return FLOAT;
		else if (lit.back() != 'f' && isDouble(lit))
			return DOUBLE;
	}
	else if (isInt(lit))
		return INT;
	return INVALID;
}

// FLOAT : need to remove trailing f for sstream conversion
bool	ScalarConverter::isFloat(std::string lit)
{
	std::string	litTrailingFRemoved;
	for (unsigned long int i = 0; i < lit.size() - 1; ++i)
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

// print DataType
void printDataType(DataType dataType)
{
	switch (dataType)
	{
		case INT:		{ std::cout << "INT"; break; }
		case CHAR:		{ std::cout << "CHAR"; break; }
		case FLOAT:		{ std::cout << "FLOAT"; break; }
		case DOUBLE:	{ std::cout << "DOUBLE"; break; }
		case INVALID:	{ std::cout << "INVALID"; break; }
		default:		{ std::cout << "UNKNOWN"; break; }
	}
	std::cout << std::endl;
}
