#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include<iostream>
#include<iomanip>
#include<string>
#include<limits>
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


#define BAD_TYPE "Input type is not recognized"

enum DataType
{
	INT,
	CHAR,
	FLOAT,
	DOUBLE,
	INVALID,
};
void printDataType(DataType dataType);

struct number
{
	std::string	literal;
	DataType	l_type;
	char		l_char;
	int			l_int;
	float		l_float;
	double		l_double;
};

class ScalarConverter
{
	public:
	
		//	main class function
		static void		convert(std::string lit);

		//	bits representation
		static void		printFloatBits(__attribute__((unused)) const float & f);
		static void		printDoubleBits(__attribute__((unused)) const double & d);
		static void		printIntBits(__attribute__((unused)) const int & i);
		static void		printCharBits(__attribute__((unused)) const char & c);

	private:

		//	contructors unusable
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(__attribute__((unused)) const ScalarConverter & src);
		ScalarConverter & operator=(const ScalarConverter & rhs);

		//	check for input type recog
		static DataType findDataType(std::string lit);
		static bool		isFloat(std::string lit);
		static bool		isDouble(std::string lit);
		static bool		isInt(std::string lit);

		//	prints converted input if possible, else err msg
		static void		FloatTo(number val);
		static void		DoubleTo(number val);
		static void		IntTo(number val);
		static void		CharTo(number val);


};

#endif
