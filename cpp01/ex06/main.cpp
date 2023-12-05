#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac != 2)
		return (std::cout << "Bad arg number. Program exits" << std::endl, 1);

	harl.cascade_complain(av[1]);
}