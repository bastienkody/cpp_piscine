#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) return (std::cerr << "One arg please" << std::endl, 2);

	ScalarConverter::convert(argv[1]);
}
