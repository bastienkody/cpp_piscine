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
					EXPLICATIONS:

	La classe ne doit pas etre instaciable : constructors et destructors en private
	
	Le "static" de convert() pewrmet a la fonction membre d'etre utilisee
	sans istancier la classe -> ScalarConverter::convert()
	Les fonctions membres "non statiques" ne sont utilisees qu'au travers
	d'une instance uniquement -> obj.function()
	Les fonctions membres utilisees par des fonctions membres statiques doivent
	aussi etre statiques (==utilisable sans instancier la classe)

	Pour le type reco from str, je prends : 
		- char: str.size == 0 + str[0]: isprint && !isdigit)
		- float: ".f" + check err (ie. 2..f) + check ovflw + warn precision
		- double: "." + check err (ie 2..) + check ovflw + warn precision
		- int: si pas autre type et pas d'overflow
	leading whitespaces and single sign are accepted. 

	Pour les check de precision float au type reco:
		- je clean dans str les potentiels leadings 0
		- je retiens le nb de decimal digits
		- je passe str dans un sstream, puis dans le type cherche.
		- je repasse du type dans un sstream avec setprecision(decimaldigits)
		- je compare le str recupere au str d'origine corrige

	Pour les conversion du type reco vers les 3 autres:
		- je check les limites pour eviter les ovlfw
		- je check les precision float/double via les strPrecise
		- sauf pour int->float ou j'ai code une fonction logique (bornes/step)
		- seule exception : le 2147483648.f qui passe dans les limites du int
		mais qui ovflw vers intmin. Je check le bit de sign du coup. 


	-.1f   ecritureb scientiufic



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

		static void		convert(std::string lit);

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
