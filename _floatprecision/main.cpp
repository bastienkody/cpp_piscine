#include "main.hpp"

int	main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
	if (ac == 2)
		std::cout << strDoublePreciseEnough(av[1]) << std::endl;
	
	std::cout << "nb:\t2147483648" << std::endl;
	std::cout << "int min:\t" << std::numeric_limits<signed int>::min()	<< std::endl;
	std::cout << "float int min:\t" << std::fixed << std::setprecision(1) << static_cast<float>(std::numeric_limits<signed int>::min()) << std::endl;
}