#include "ScalarConverter.hpp"

int	main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
/*	
	if (argc != 2) 
		return (std::cerr << "One arg please" << std::endl, 2);
	ScalarConverter::convert(argv[1]);
*/

	ScalarConverter::printCharBits(0);
	ScalarConverter::printCharBits(1);
	ScalarConverter::printCharBits(2);
	ScalarConverter::printCharBits(4);
	ScalarConverter::printCharBits(8);
	ScalarConverter::printCharBits(16);
	ScalarConverter::printCharBits(32);
	ScalarConverter::printCharBits(64);
	ScalarConverter::printCharBits(127);
	ScalarConverter::printCharBits(-1);
	ScalarConverter::printCharBits(-125);
}
