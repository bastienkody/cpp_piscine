#include "main.hpp"

/* 
	-->  sstream << d met 6 floating (idem float)

	On remet autant de décimaux que src avait (size_t floatings)
*/

std::string	strNormalizeFloatings(std::string src, size_t floatings)
{
	std::string	str(src);
	
	while (str.size() - str.find('.') - 1 < floatings)
		str += '0';
	return (str);
}

//	can d genuinely store str (loss of precision?)
bool	strDoublePreciseEnough(std::string str)
{
	size_t				floatings = str.size() - str.find('.') - 1;
	std::stringstream	ss_double(str);
	double				d;
	ss_double >> d;

	std::stringstream	ss_re_double;
	ss_re_double << std::fixed << std::setprecision(floatings) << d;

	std::cout << "ssre:\t" << ss_re_double.str() << std::endl;
	std::cout << "str:\t" << strNormalizeFloatings(str, floatings) << std::endl;

	if (ss_re_double.str().compare(strNormalizeFloatings(str, floatings)) == 0)
		return true;
	return false;
}

