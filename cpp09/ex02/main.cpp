#include "PmergeMe.hpp"
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
	//std::cout << "comp" << a.val << "<" << b.val << std::endl;
	return ++g_comp, a < b;
}

int jacob(int n)
{
	return (std::pow(2, n+1) + std::pow(-1, n)) / 3;
}


// this test of 21 nb uses 67 comparisons (66 should be worst case)
// ./PmergeMe 58 1 45 73 14 35 75 79 88 62 28 37 36 77 10 51 100 70 63 93 7

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

	print_cont_val(p.getVec());
	p.fja_Lst(p.getLstMod());
	std::cout << "List Comparisons:" << g_comp  << std::endl;
	g_comp = 0;
	p.fja_Vec(p.getVecMod());
	std::cout << "Vec Comparisons:" << g_comp << std::endl;


//	p.fja();
	return 0;
}
