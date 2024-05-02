#include "BitcoinExchange.hpp"

inline void	badArg() {std::cout << "Expected one argument: bitcoin stocks file" << std::endl;}

int	main(int ac, char **av)
{
	if (ac != 2)
		return badArg(), 2;
	
	BitcoinExchange	btc;
	try {
		btc.readDb();
		btc.readInput(av[1]);
	}
	catch(const std::exception& e) {
		return std::cerr << e.what() << std::endl, 2;
	}
	btc.conversion();
	return (0);
}
