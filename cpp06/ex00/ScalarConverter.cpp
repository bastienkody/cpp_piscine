#include"ScalarConverter.hpp"

//	Unusable cons/des - tructors
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter & src) {*this = src;}
ScalarConverter & ScalarConverter::operator=(__attribute__((unused)) const ScalarConverter & rhs) {return (*this);}

// Convert (mix sstream and parsing)
void ScalarConverter::convert(std::string lit)
{
	number	val;

	val.literal = lit;
	val.l_type = findDataType(lit);
	printDataType(val.l_type);
	switch (val.l_type)
	{	
		case CHAR:		{ toChar(val); break; }
		case INT:		{ toInt(val); break; }
		case FLOAT:		{ toFloat(val); break; }
		case DOUBLE:	{ toDouble(val); break; }
		default:		{ std::cerr << BAD_TYPE << std::endl; break ; }
	}
}

DataType ScalarConverter::findDataType(std::string lit)
{
	if (lit.size() == 1 && !isdigit(lit[0]) && isprint(lit[0])) 
		return CHAR;
	else if (!lit.compare("-inff") || !lit.compare("+inff")|| !lit.compare("nanf"))
		return FLOAT;
	else if (!lit.compare("-inf") || !lit.compare("+inf") || !lit.compare("nan"))
		return DOUBLE;
	else if (lit.find('.') != std::string::npos)
	{
		if (lit[lit.size() - 1] == 'f' && isFloat(lit))
			return FLOAT;
		else if (lit[lit.size() - 1]!= 'f' && isDouble(lit))
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

void	ScalarConverter::toFloat(number val)
{
	std::string	litTrailingFRemoved;
	for (unsigned long int i = 0; i < val.literal.size() - 1; ++i)
		litTrailingFRemoved += val.literal[i];
	std::stringstream	ss_float(val.literal);
	ss_float >> val.l_float;

	if (!val.literal.compare("-inff"))
		val.l_float = -std::numeric_limits<float>::infinity();
	else if (!val.literal.compare("+inff"))
		val.l_float = std::numeric_limits<float>::infinity();
	else if (!val.literal.compare("nanf"))
		val.l_float = std::numeric_limits<float>::quiet_NaN();

	//char
	if (val.l_float >= std::numeric_limits<signed char>::min() && val.l_float <= std::numeric_limits<signed char>::max())
	{
		val.l_char = static_cast<char>(val.l_float);
		if (isprint(val.l_char))
			std::cout << "" << val.l_char << std::endl;
		else
			std::cout << "char:\tnon displayable" << std::endl;
	}
	else
		std::cout << "char:\timpossible" << std::endl;
	//int
	if (val.l_float >= static_cast<float>(std::numeric_limits<signed int>::min()) && val.l_float <= static_cast<float>(std::numeric_limits<signed int>::max())\
		&& val.l_float == static_cast<float>(static_cast<int>(val.l_float)))
		std::cout << "int:\t" << static_cast<int>(val.l_float) << std::endl;
	else { std::cout << "int:\timpossible" << std::endl; }
	//float
	std::cout << "float:\t" << std::fixed  << val.l_float << 'f' << std::endl;
	//double
	if (isDouble(litTrailingFRemoved) || !litTrailingFRemoved.compare("+inf") || !litTrailingFRemoved.compare("-inf") || !litTrailingFRemoved.compare("nan"))
		std::cout << "double:\t" << std::fixed  << static_cast<double>(val.l_float) << std::endl;
	else { std::cout << "double:\timpossible" << std::endl; }
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

void	ScalarConverter::toDouble(number val)
{
	std::stringstream	ss_double(val.literal);
	ss_double >> val.l_double;

	if (!val.literal.compare("-inf"))
		val.l_double = -std::numeric_limits<double>::infinity();
	else if (!val.literal.compare("+inf"))
		val.l_double= std::numeric_limits<double>::infinity();
	else if (!val.literal.compare("nan"))
		val.l_double = std::numeric_limits<double>::quiet_NaN();

	//char
	if (val.l_double >= std::numeric_limits<signed char>::min() && val.l_double <= std::numeric_limits<signed char>::max())
	{
		val.l_char = static_cast<char>(val.l_double);
		if (isprint(val.l_char))
			std::cout << "char:\t" << val.l_char << std::endl;
		else
			std::cout << "char:\tnon displayable" << std::endl;
	}
	else
		std::cout << "char:\timpossible" << std::endl;
	//int
	if (val.l_double >= static_cast<double>(std::numeric_limits<signed int>::min()) && val.l_double <= static_cast<double>(std::numeric_limits<signed int>::max()))
		std::cout << "int:\t" << static_cast<int>(val.l_double) << std::endl; 
	else { std::cout << "int:\timpossible" << std::endl; }
	//float
	std::cout << "float:\t" << std::fixed << static_cast<float>(val.l_double) << 'f';
	if (val.l_double != static_cast<double>(static_cast<float>(val.l_double)))
		std::cout << " (possible loose of precision)";
	std::cout << std::endl;
	//double
	std::cout << "double:\t" << std::fixed  << val.l_double << std::endl;
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

void	ScalarConverter::toInt(number val)
{
	std::stringstream	ss_int(val.literal);
	ss_int >> val.l_int;

	//char
	if (val.l_int >= std::numeric_limits<signed char>::min() && val.l_int <= std::numeric_limits<signed char>::max())
	{
		val.l_char = static_cast<char>(val.l_int);
		if (isprint(val.l_char))
			std::cout << "char:\t" << val.l_char << std::endl;
		else
			std::cout << "char:\tnon displayable" << std::endl;
	}
	else { std::cout << "char:\timpossible" << std::endl; }
	//int
	std::cout << "int:\t"<< val.l_int << std::endl;
	//float
	std::cout << "float:\t" << std::fixed << std::setprecision(1) << static_cast<float>(val.l_int) << 'f' ;
	if (val.l_int != static_cast<int>(static_cast<float>(val.l_int)))
		std::cout << " (possible loose of precision)";
	std::cout << std::endl;
	//double
	std::cout << "double:\t" << std::fixed << std::setprecision(1) << static_cast<double>(val.l_int)<< std::endl;
}

//	CHAR
void	ScalarConverter::toChar(number val)
{
	val.l_char = val.literal[0];

	std::cout << "char:\t"<< val.l_char << std::endl;
	std::cout << "int:\t" << static_cast<int>(val.l_char) << std::endl;
	std::cout << "float:\t" << std::fixed << std::setprecision(1) << static_cast<float>(val.l_char) << 'f' << std::endl;
	std::cout << "double:\t" << std::fixed << std::setprecision(1) << static_cast<double>(val.l_char) << std::endl;
}

// print DataType
void printDataType(DataType dataType)
{
	switch (dataType)
	{
		case INT:		{ std::cout << "Input type found: INT" << std::endl; break; }
		case CHAR:		{ std::cout << "Input type found: CHAR" << std::endl; break; }
		case FLOAT:		{ std::cout << "Input type found: FLOAT" << std::endl; break; }
		case DOUBLE:	{ std::cout << "Input type found: DOUBLE" << std::endl; break; }
		default:		break;
	}
}
