#include"ScalarConverter.hpp"

/*
	DATATYPE FUNCTIONS
	with enum DataType
*/
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


/*
	BOOL TYPECHECK FUNCTION	
	use of stringstream handles overflows
*/

// FOAT : trailing f removed for sstream conversion
bool	ScalarConverter::isFloat(std::string lit)
{
	std::string			litClean(lit);
	if (lit[lit.size() - 1] == 'f')
		litClean.erase(litClean.end() - 1);

	std::stringstream	ss_float(litClean);
	float				f;
	
	ss_float >> f;
	if (!ss_float.fail() && ss_float.eof())
		return true;
	return false;
}

// DOUBLE
bool	ScalarConverter::isDouble(std::string lit)
{
	std::stringstream	ss_double(lit);
	double				d;

	ss_double >> d;
	if (!ss_double.fail() && ss_double.eof())
		return true;
	return false;
}

// INT 
bool	ScalarConverter::isInt(std::string lit)
{
	std::stringstream	ss_int(lit);
	int					i;

	ss_int >> i;
	if (!ss_int.fail() && ss_int.eof())
		return true;
	return false;
}
