#include "main.hpp"

/* 
	-->  sstream << f met toujours exactement 6 decimaux. 
	on modifie argv1 pour rajouter des 0 tant que < 6 decimaux !
	et comparer argv1_6_decimal au sstream.str() !!!!
	on aura deja enleve le 'f' de argv1
	il y aura toujours un '.' dans argv1 

	--> marche bien (yc. negattifs, precision float et entiere)
	Seul pb : si on me donne un float avec plus de 6 decimaux acceptés, je ne
	le recupère de sstrezam qu'avec 6 du coup / false. 
	Mais "souvent" pb de precision à plus de 5-6 decimaux. 

*/

//	normalize 6 float digits (== sstream >> f). src has no 'f' but a single '.'
std::string	strSixFloatings(std::string src)
{
	std::string	str(src);
	
	while (str.size() - str.find('.') - 1 < 6)
		str += '0';
	return (str);
}

//	can f genuinely store str (loss of precision?)
bool	strFloatPreciseEnough(std::string str)
{
	std::stringstream	ss_float(str);
	float				f;
	ss_float >> f;

	std::stringstream	ss_re_float;
	ss_re_float << std::fixed  << f;

	std::cout << "str:\t" << strSixFloatings(str) << std::endl;
	std::cout << "ssre:\t" << ss_re_float.str() << std::endl;

	if (ss_re_float.str().compare(strSixFloatings(str)) == 0)
		return true;
	return false;
}

