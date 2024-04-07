#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include<iostream>
#include<iomanip>
#include<string>
#include<limits>
#include<cstdlib>
#include<cmath>
#include <sstream>


/*
	La classe ne doit pas etre instaciable : constructors et destructors en private
	
	Le "static" de convert() pewrmet a la fonction membre d'etre utilisee
	sans istancier la classe -> ScalarConverter::convert()
	Les fonctions membres "non statiques" ne sont utilisees qu'au travers
	d'une instance uniquement -> obj.function()
*/


#define BAD_TYPE "Input type is not recognized"

#define _CHAR_MIN std::numeric_limits<signed char>::min()
#define _CHAR_MAX std::numeric_limits<signed char>::max()
#define _INT_MIN std::numeric_limits<signed int>::min()
#define _INT_MAX std::numeric_limits<signed int>::max()
#define _FLOAT_MIN -std::numeric_limits<float>::max()
#define _FLOAT_MAX std::numeric_limits<float>::max()


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

		//	unusable contructors 
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(__attribute__((unused)) const ScalarConverter & src);
		ScalarConverter & operator=(const ScalarConverter & rhs);

		//	input type recog
		static DataType findDataType(std::string lit);
		static bool		isFloat(std::string lit);
		static bool		isDouble(std::string lit);
		static bool		isInt(std::string lit);

		//	prints converted input
		static void		FloatTo(number val);
		static void		DoubleTo(number val);
		static void		IntTo(number val);
		static void		CharTo(number val);

		//	floating precision check
		static bool			intFloatPreciseEnough(int nb);
		static std::string	strNormalizeFloatings(std::string src, size_t floatings);
		static std::string	strNormalizeInteger(std::string src);
		static bool			strFloatPreciseEnough(std::string str);
		static bool			strDoublePreciseEnough(std::string str);
};

#endif
