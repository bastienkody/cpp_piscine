#include "ScalarConverter.hpp"

int	main(__attribute__((unused))int argc, __attribute__((unused))char **argv)
{
	if (argc != 2) 
		return (std::cerr << "One arg please" << std::endl, 2);
	ScalarConverter::convert(argv[1]);
}
