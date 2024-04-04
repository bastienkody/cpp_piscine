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
	float -> char	: checks limits
	float -> int 	: checks limits + precision (ko if possible loss) TO BE CHANGED
	float -> float	: ras same type
	float -> double	: ras promotion
	str   -> float	: possible loss of precision unchecked !!
*/
void	ScalarConverter::FloatTo(number val)
{
	std::string			litClean(val.literal);
	if (litClean[litClean.size() - 1] == 'f')
		litClean.erase(litClean.end() - 1);

	std::stringstream	ss_float(litClean);

	if (!val.literal.compare("-inff"))
		val.l_float = -std::numeric_limits<float>::infinity();
	else if (!val.literal.compare("+inff"))
		val.l_float = std::numeric_limits<float>::infinity();
	else if (!val.literal.compare("nanf"))
		val.l_float = std::numeric_limits<float>::quiet_NaN();
	else
		ss_float >> val.l_float;

	//char
	if (val.l_float >= static_cast<float>(std::numeric_limits<signed char>::min()) && val.l_float <= static_cast<float>(std::numeric_limits<signed char>::max()))
	{
		val.l_char = static_cast<char>(val.l_float);
		if (isprint(val.l_char)) 	std::cout << "char:\t" << val.l_char << std::endl;
		else 						std::cout << "char:\tnon displayable" << std::endl;
	}
	else
		std::cout << "char:\timpossible" << std::endl;
	//int
	if (val.l_float >= static_cast<float>(std::numeric_limits<signed int>::min()) && val.l_float <= static_cast<float>(std::numeric_limits<signed int>::max()))
	{
		std::cout << "int:\t" << static_cast<int>(val.l_float);
		if (val.l_float == static_cast<float>(static_cast<int>(val.l_float)))
			std::cout << " (possible loose of precision)";
		std::cout << std::endl;
	}
	else	
		std::cout << "int:\timpossible" << std::endl;
	//float
	std::cout << "float:\t" << std::fixed  << val.l_float << 'f' << std::endl;
	//double
	std::cout << "double:\t" << std::fixed  << static_cast<double>(val.l_float) << std::endl;
}

/*
	double -> char	: checks limits
	double -> int 	: checks limits + precision (ko if possible loss)
	double -> float	: checks limits + precision message (need to recheck bc outputs a lot)
	double -> doubl	: same type
	str    -> doubl	: possible loss of precision unchecked !!
*/
void	ScalarConverter::DoubleTo(number val)
{
	std::stringstream	ss_double(val.literal);

	if (!val.literal.compare("-inf"))
		val.l_double = -std::numeric_limits<double>::infinity();
	else if (!val.literal.compare("+inf"))
		val.l_double= std::numeric_limits<double>::infinity();
	else if (!val.literal.compare("nan"))
		val.l_double = std::numeric_limits<double>::quiet_NaN();
	else
		ss_double >> val.l_double;

	//char
	if (val.l_double >= static_cast<double>(std::numeric_limits<signed char>::min()) && val.l_double <= static_cast<double>(std::numeric_limits<signed char>::max()))
	{
		val.l_char = static_cast<char>(val.l_double);
		if (isprint(val.l_char))	std::cout << "char:\t" << val.l_char << std::endl;
		else						std::cout << "char:\tnon displayable" << std::endl;
	}
	else
		std::cout << "char:\timpossible" << std::endl;
	//int
	if (val.l_double >= static_cast<double>(std::numeric_limits<signed int>::min()) && val.l_double <= static_cast<double>(std::numeric_limits<signed int>::max()))
		std::cout << "int:\t" << static_cast<int>(val.l_double) << std::endl; 
	else 
		std::cout << "int:\timpossible" << std::endl;
	//float
	if (!val.literal.compare("-inf") || !val.literal.compare("+inf") || !val.literal.compare("nan"))
		std::cout << "float:\t" << std::fixed << static_cast<float>(val.l_double) << 'f' << std::endl;
	else
	{
		if (val.l_double >= static_cast<double>(-std::numeric_limits<float>::max()) && val.l_double <= static_cast<double>(std::numeric_limits<float>::max()))
			std::cout << "float:\t" << std::fixed << static_cast<float>(val.l_double) << 'f';
		if (val.l_double != static_cast<double>(static_cast<float>(val.l_double))) 
			std::cout << " (possible loose of precision)";
		std::cout << std::endl;
	}	
	//double
	std::cout << "double:\t" << std::fixed  << val.l_double << std::endl;
}

/*
	int -> char		: checks limits
	int -> int 		: same type
	int -> float	: promotion, but precision message !
	int -> double	: promotion, no lack of precision until int_Max so no msg
	str -> int		: should be no loss of precision, overflow handled
*/
void	ScalarConverter::IntTo(number val)
{
	std::stringstream	ss_int(val.literal);
	ss_int >> val.l_int;

	//char
	if (val.l_int >= static_cast<int>(std::numeric_limits<signed char>::min()) && val.l_int <= static_cast<int>(std::numeric_limits<signed char>::max()))
	{
		val.l_char = static_cast<char>(val.l_int);
		if (isprint(val.l_char))	std::cout << "char:\t" << val.l_char << std::endl;
		else						std::cout << "char:\tnon displayable" << std::endl;
	}
	else 
		std::cout << "char:\timpossible" << std::endl;
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

/*
	char -> char	: same type
	char -> int 	: promotion
	char -> float	: promotion, no lack of precision until char max
	char -> double	: promotion, no lack of precision until char max
	str -> char		: sstream bugs so using index (size==1 check done before)
*/
void	ScalarConverter::CharTo(number val)
{
	val.l_char = val.literal[0];

	std::cout << "char:\t"<< val.l_char << std::endl;
	std::cout << "int:\t" << static_cast<int>(val.l_char) << std::endl;
	std::cout << "float:\t" << std::fixed << std::setprecision(1) << static_cast<float>(val.l_char) << 'f' << std::endl;
	std::cout << "double:\t" << std::fixed << std::setprecision(1) << static_cast<double>(val.l_char) << std::endl;
}
