#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include<iostream>
#include<string>
#include <sstream>


/*
	La classe ne doit pas etre instaciable : constructors et destructors en private
	
	Le "static" de convert() pewrmet a la fonction membre d'etre utilisee
	sans istancier la classe -> ScalarConverter::convert()
	Les fonctions membres "non statiques" ne sont utilisees qu'au travers
	d'une instance uniquement -> obj.function()
*/

/*	CHOICES
	- a single digit is reco as an int, not a char (ie: "1" == (int)1 not (int)49)
		this can easily be changed is the parsing (lit.size==1 && isprint(lit[0]))
	- spaces not manually handled, might get accepted via sstream flush but probably not
	- leading '-' or '+' are handled via sstream conv ('-' ok, '+' nsp)

*/

/*	TYPE RECOGNITION algo for a PARSING METHOD :
	- if lit.size() == 0 : BAD ARG
	- if lit.size() == 1
		- if isdigit : INT
		- if (isprint) : CHAR
		- else : BAD ARG
	- else several character :
		- if (lit.compare("-inff", "+inff")) : FLOAT
		- else if (lit.compare("-inf", "+inf", "nan")) : DOUBLE
		- else if (isdigit(lit_all) || (lit[0] == '-' && isdigit(lit_all + 1)) : INT
			--> overflows to be checked
		- else if (point_pos = strfind(lit, '.')) : FLOAT, DOUBLE, BAD ARG
			- if (point_pos = lit.begin() || lit.end()) : BAD ARG
				--> now we are sure '.' is not first nor last char
			- else if ( (lit.begin() == '-' || isdigit(lit.begin())) &&
						isdigit(lit_all except begin, end, point_pos) : FLOAT, DOUBLE
				- if (lit.end == 'f) : FLOAT
				- else if (isdigit(lit.end())) : DOUBLE
				- else : BAD ARG
		- else : BAD ARG
*/

enum DataType {
	INT,
	CHAR,
	FLOAT,
	DOUBLE,
	INVALID,
};
void printDataType(DataType dataType);

class ScalarConverter
{
	public:
		//static void convertFullParsing(std::string lit);
		static DataType convert(std::string lit);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(__attribute__((unused)) const ScalarConverter & src);
		ScalarConverter & operator=(const ScalarConverter & rhs);

		//static bool	isStringOnly(std::string str, size_t offset, int(*fct)(int));
		
		static bool	isFloat(std::string lit);
		static bool	isDouble(std::string lit);
		static bool	isInt(std::string lit);
};

#endif
