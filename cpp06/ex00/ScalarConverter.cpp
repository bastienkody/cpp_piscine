#include"ScalarConverter.hpp"

//	Unusable cons/des - tructors
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter & src) {*this = src;}
ScalarConverter & ScalarConverter::operator=(__attribute__((unused)) const ScalarConverter & rhs) {return (*this);}

// Converters
void ScalarConverter::convert(std::string lit)
{
	number	val;

	if (lit.size() > 1 && (lit.find('e') != std::string::npos || lit.find('E') != std::string::npos))
		{std::cout << NO_SCIENTIFIC << std::endl; return; }
	val.literal = lit;
	val.l_type = findDataType(lit);
	printDataType(val.l_type);
	switch (val.l_type)
	{	
		case CHAR:		{ CharTo(val); break; }
		case INT:		{ IntTo(val); break; }
		case FLOAT:		{ FloatTo(val); break; }
		case DOUBLE:	{ DoubleTo(val); break; }
		default:		{ std::cerr << BAD_TYPE << std::endl; break ; }
	}
}

/*
	str   -> float	: precision warning
	float -> char	: checks limits
	float -> int 	: checks limits + check sign bit for int_max+1
	float -> float	: 
	float -> double	: promotion
*/
void	ScalarConverter::FloatTo(number val)
{
	//conv to float
	if (!val.literal.compare("-inff"))
		val.l_float = -std::numeric_limits<float>::infinity();
	else if (!val.literal.compare("+inff"))
		val.l_float = std::numeric_limits<float>::infinity();
	else if (!val.literal.compare("nanf"))
		val.l_float = std::numeric_limits<float>::quiet_NaN();
	else
	{
		std::string	litClean(val.literal);
		if (litClean[litClean.size() - 1] == 'f')
			litClean.erase(litClean.end() - 1);
		std::stringstream	ss_float(litClean);
		ss_float >> val.l_float;
		if (strFloatPreciseEnough(litClean) == false)
			std::cout << WARN_PRECISION << val.literal << " as a float\033[m" << std::endl;
	}

	//char
	if (val.l_float >= static_cast<float>(_CHAR_MIN) && val.l_float <= static_cast<float>(_CHAR_MAX))
	{
		val.l_char = static_cast<char>(val.l_float);
		if (isprint(val.l_char)) 	std::cout << "char:\t" << val.l_char << std::endl;
		else 						std::cout << "char:\tnon displayable\t(int:" << static_cast<int>(val.l_char) << ')' << std::endl;
	}
	else
		std::cout << "char:\timpossible" << std::endl;
	//int
	if (val.l_float >= static_cast<float>(_INT_MIN) && val.l_float <= static_cast<float>(_INT_MAX) &&
		 (static_cast<int>(val.l_float) == 0 || ((static_cast<int>(val.l_float) >> 31 & 1) == (reinterpret_cast<unsigned int *>(&val.l_float)[0] >> 31 & 1)) ) )
			std::cout << "int:\t" << static_cast<int>(val.l_float) << std::endl;
	else
		std::cout << "int:\timpossible" << std::endl;
	//float - double
	std::cout << "float:\t" << std::fixed  << val.l_float << 'f' << std::endl;
	std::cout << "double:\t" << std::fixed  << static_cast<double>(val.l_float) << std::endl;
}

/*
	str    -> doubl	: precision checked
	double -> char	: checks limits
	double -> int 	: checks limits + no precision matter until int_max
	double -> float	: checks limits + precision check done via strFloatPrecise(val.literal)
	double -> doubl	: 
*/
void	ScalarConverter::DoubleTo(number val)
{
	//conv to double
	if (!val.literal.compare("-inf"))
		val.l_double = -std::numeric_limits<double>::infinity();
	else if (!val.literal.compare("+inf"))
		val.l_double= std::numeric_limits<double>::infinity();
	else if (!val.literal.compare("nan"))
		val.l_double = std::numeric_limits<double>::quiet_NaN();
	else
	{
		std::stringstream	ss_double(val.literal);
		ss_double >> val.l_double;
		if (strDoublePreciseEnough(val.literal) == false)
			std::cout << WARN_PRECISION << val.literal << " as a double\033[m" << std::endl;
	}

	//char
	if (val.l_double >= static_cast<double>(_CHAR_MIN) && val.l_double <= static_cast<double>(_CHAR_MAX))
	{
		val.l_char = static_cast<char>(val.l_double);
		if (isprint(val.l_char))	std::cout << "char:\t" << val.l_char << std::endl;
		else						std::cout << "char:\tnon displayable\t(int:" << static_cast<int>(val.l_char) << ')' << std::endl;
	}
	else
		std::cout << "char:\timpossible" << std::endl;
	//int
	if (val.l_double >= static_cast<double>(_INT_MIN) && val.l_double <= static_cast<double>(_INT_MAX))
		std::cout << "int:\t" << static_cast<int>(val.l_double) << std::endl; 
	else 
		std::cout << "int:\timpossible" << std::endl;
	//float + impossibnle pour ovlfw
	if (!val.literal.compare("-inf") || !val.literal.compare("+inf") || !val.literal.compare("nan"))
		std::cout << "float:\t" << std::fixed << static_cast<float>(val.l_double) << 'f' << std::endl;
	else
	{
		if (val.l_double >= static_cast<double>(_FLOAT_MIN) && val.l_double <= static_cast<double>(_FLOAT_MAX))
		{
			std::cout << "float:\t" << std::fixed << static_cast<float>(val.l_double) << 'f';
			if (!strFloatPreciseEnough(val.literal))
				std::cout << FLOAT_LACK ;
			std::cout << std::endl;
		}
		else
			std::cout << "float:\timpossible" << std::endl;
	}	
	//double
	std::cout << "double:\t" << std::fixed  << val.l_double << std::endl;
}

/*
	str -> int		: no loss of precision, overflow handled
	int -> char		: checks limits
	int -> int 		: 
	int -> float	: promotion, but precision matter for > 2^24 
	int -> double	: promotion, no lack of precision until int_max 
*/
void	ScalarConverter::IntTo(number val)
{
	std::stringstream	ss_int(val.literal);
	ss_int >> val.l_int;

	//char
	if (val.l_int >= static_cast<int>(_CHAR_MIN) && val.l_int <= static_cast<int>(_CHAR_MAX))
	{
		val.l_char = static_cast<char>(val.l_int);
		if (isprint(val.l_char))	std::cout << "char:\t" << val.l_char << std::endl;
		else						std::cout << "char:\tnon displayable\t(int:" << static_cast<int>(val.l_char) << ')' << std::endl;
	}
	else 
		std::cout << "char:\timpossible" << std::endl;
	//int
	std::cout << "int:\t"<< val.l_int << std::endl;
	//float
	std::cout << "float:\t" << std::fixed << std::setprecision(1) << static_cast<float>(val.l_int) << 'f' ;
	if (!intFloatPreciseEnough(val.l_int))
		std::cout << FLOAT_LACK ;
	std::cout << std::endl;
	//double
	std::cout << "double:\t" << std::fixed << std::setprecision(1) << static_cast<double>(val.l_int)<< std::endl;
}

/*
	str -> char		: sstream bugs so using index (size==1 check done before)
	char -> char	: 
	char -> int 	: promotion
	char -> float	: promotion, no lack of precision until char max
	char -> double	: promotion, no lack of precision until char max
*/
void	ScalarConverter::CharTo(number val)
{
	val.l_char = val.literal[0];

	std::cout << "char:\t"<< val.l_char << std::endl;
	std::cout << "int:\t" << static_cast<int>(val.l_char) << std::endl;
	std::cout << "float:\t" << std::fixed << std::setprecision(1) << static_cast<float>(val.l_char) << 'f' << std::endl;
	std::cout << "double:\t" << std::fixed << std::setprecision(1) << static_cast<double>(val.l_char) << std::endl;
}
