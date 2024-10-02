#include "PmergeMe.hpp"
#include <sstream>

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
	return a > b;
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return std::cerr << "Expecting a sequence of positive integers" << std::endl, 2;

	PmergeMe	p;
	nb			nb;

	for (int i=1; i<ac; ++i)
	{
		try {
			nb.val = conv_to_int(av[i]);
			p.add_to_vec(nb);
			p.add_to_lst(nb);
		} catch (const std::exception &e) {
			return std::cerr << e.what() << std::endl, 2;
		}
	}

/*	print_cont_val(p.getLst());
	print_cont_val(p.getVec());
	pairing(p.getVecMod());
	pairing(p.getLstMod());
	print_cont_detail(p.getVec());
	print_cont_detail(p.getLst());
*/
	p.fja(p.getVecMod());
	return 0;
}
