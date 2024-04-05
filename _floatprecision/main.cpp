#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<limits>
#include<cstdlib>
#include<cmath>

int	main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	if (argc != 2)
		return 2;

	std::stringstream	ss_float(argv[1]);
	float				f;

	std::cout << "av1:\t" << argv[1] << std::endl;
	std::cout << "ss:\t" << ss_float.str() << std::endl;

	ss_float >> f;
	std::cout << "f:\t" << std::fixed << std::setprecision(0) << f << std::endl;

	std::cout << (ss_float.fail() ? "ss failbit on" : "ss failbit off") << std::endl;
	std::cout << (ss_float.eof() ? "ss eof on" : "ss eof off") << std::endl;

	// Part 2 : convert back to str
	std::stringstream	ss_re_float;
	ss_re_float << std::fixed  << f;

	std::cout << "ss_re:\t" << ss_re_float.str() << std::endl;

	std::cout << (ss_re_float.fail() ? "ss failbit on" : "ss failbit off") << std::endl;
	std::cout << (ss_re_float.eof() ? "ss eof on" : "ss eof off") << std::endl;

	/* problem lie au convert back de f dans un sstream :
	je voudrai comparer le sstream.str avec argv1 mais le float est balance dans
	le sstream en ecriture scientifique : je std::fixed, ya 6 decimal. Je peux
	setprecision(0) mais on a encore le pb du .f - et quid si il y avait des decimal
	dans le float de depart.
	On peut ne checker que la partie entiere mais du coup je fais un taff pour
	les entiers que je ne fais pas pour les decimaux ...

	-->  sstream << f met toujours exactement 6 decimaux. 
	on peut modifier argv1 pour rajouter des 0 tant que < 6 decimaux !
	et comparer argv1_6_decimal au sstream.str() !!!!
	on aura enlever le 'f' de argv1
	il y aura toujours un '.' pour etre detect comme float

	idees pour conv back:
	https://www.geeksforgeeks.org/convert-float-to-string-in-cpp/
	*/
}
