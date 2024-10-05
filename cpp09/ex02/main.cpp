#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <sstream>

static unsigned long int g_comp = 0;

int	conv_to_int(std::string entry)
{
	std::stringstream	sstr(entry);
	int					res;

	sstr >> res;
	if (sstr.fail() || sstr.eof() == false || res < 0)
		throw std::invalid_argument("Bad input: " + entry);
	return res;
}

bool	comp(const nb & a, const nb & b)
{
	return ++g_comp, a < b;
}

int jacob(int n)
{
	return (std::pow(2, n+1) + std::pow(-1, n)) / 3;
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return std::cerr << "Expecting a sequence of positive integers" << std::endl, 2;

	PmergeMe	p;
	nb			nbr;

	for (int i=1; i<ac; ++i)
	{
		try {
			nbr.val = conv_to_int(av[i]);
			p.add_to_vec(nbr);
			p.add_to_lst(nbr);
		} catch (const std::exception &e) {
			return std::cerr << e.what() << std::endl, 2;
		}
	}

	p.fja();
//	std::cout << "Comparisons:" << g_comp / 2 << std::endl;
	return 0;
}
