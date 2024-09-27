#include <iostream>
#include "PmergeMe.hpp"
#include "PmergeMeList.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
		return std::cerr << "Expecting a sequence of positive integers" << std::endl, 2;

	PmergeMe	v;
	PmergeMeList	l;
	nb	nb;

	for (int i=1; i<ac; ++i)
	{
		try {
			nb.val = conv_to_int(av[i]);
			v.add_to_vec(nb);
			l.add_to_lst(nb);
		} catch (const std::exception &e) {
			return std::cerr << e.what() << std::endl, 2;
		}
	}

	print_vec(v.getVec());
	print_lst(l.getLst());
	pairing(v.getVecMod());

	return 0;
}
