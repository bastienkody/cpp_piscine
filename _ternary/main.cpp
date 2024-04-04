#include <iostream>
#include <string>

/*
	How can i use ternary with iostream operator << ?

	1 - need parenthese around the all ternary to be seen as one arg
	2 - both results need to be same type ! (you can typecast)
*/


void	test1(void)
{
	char	zero = 65;

	std::cout << "char zero:\t" << (isprint(zero) ? "printable" : "not printable") << std::endl;
	std::cout << "char zero:\t" << (isprint(zero) ? zero : "not printable") << std::endl;// 							-> type are not the same

	// We can turn char to const char * but outputs would have trailing random value
	std::cout << "char zero:\t" << (isprint(zero) ? (const char *)&zero : "not printable") << std::endl;//				-> awful cast
	std::cout << "char zero:\t" << (isprint(zero) ? const_cast<const char *>(&zero) : "not printable") << std::endl;//	-> nicer cast
}

int	main(void)
{
	if (true) test1();
}