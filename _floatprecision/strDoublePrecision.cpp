#include "main.hpp"

/* 
	-->  sstream << d met 6 floating (idem float)

	On va rester sur 6 decimaux comme le float. 
	J'arrive pas à trouver un pattern max ; j'ai des precision pour deverser un
	sstring dans un double jusqu'a plus de 500 digits apres virgule ...
	De base le sstream en met 6, peut importe la taille du double
*/

//	normalize 6 float digits (== sstream >> f). src has no 'f' but a single '.'
std::string	strNormalizeFloatingsDouble(std::string src)
{
	std::string	str(src);
	
	while (str.size() - str.find('.') - 1 < 6)
		str += '0';
	return (str);
}

//	can d genuinely store str (loss of precision?)
bool	strDoublePreciseEnough(std::string str)
{
	std::stringstream	ss_double(str);
	double				d;
	ss_double >> d;

	std::stringstream	ss_re_double;
	ss_re_double << std::fixed << d;

	//std::cout << "str:\t" << strSixFloatings(str) << std::endl;
	std::cout << "ssre:\t" << ss_re_double.str() << std::endl;
	std::cout << "str:\t" << strNormalizeFloatingsDouble(str) << std::endl;

	if (ss_re_double.str().compare(strNormalizeFloatingsDouble(str)) == 0)
		return true;
	return false;
}

