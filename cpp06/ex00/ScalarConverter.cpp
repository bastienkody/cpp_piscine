#include"ScalarConverter.hpp"

//	Default constructor
ScalarConverter::ScalarConverter() {}

//	Default destructor
ScalarConverter::~ScalarConverter() {}

//	Copy constructor (via copy operator)
ScalarConverter::ScalarConverter(const ScalarConverter & src) {*this = src;}

//	Copy operator
ScalarConverter & ScalarConverter::operator=(const ScalarConverter & rhs) {return (*this);}

// Convert
void ScalarConverter::convert(std::string lit)
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
