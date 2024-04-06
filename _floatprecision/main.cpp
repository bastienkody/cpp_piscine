#include "main.hpp"

int	main(__attribute__((unused))int ac, __attribute__((unused))char **av)
{
	if (ac == 2)
		std::cout << strDoublePreciseEnough(av[1]) << std::endl;
}