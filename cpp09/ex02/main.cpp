#include "PmergeMe.hpp"
#include "PmergeMeList.hpp"
#include <algorithm>

int	main(int ac, char **av)
{
	if (ac < 2)
		return std::cerr << "Expecting a sequence of positive integers" << std::endl, 2;

	PmergeMe		v;
	PmergeMeList	l;
	nb				nb;

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

	print_cont_val(v.getVec());
	print_cont_val(l.getLst());

	pairingT(v.getVecMod());
	pairingT(l.getLstMod());

	print_cont_detail(v.getVec());
	print_cont_detail(l.getLst());

	nb.val = 5;
	std::vector<struct nb>::iterator res = b_search< std::vector<struct nb> >(v.getVecMod().begin(), v.getVecMod().end(), nb);
	std::cout << "vec:" << res->val <<std::endl;
	std::list<struct nb>::iterator resL = b_search< std::list<struct nb> >(l.getLstMod().begin(), l.getLstMod().end(), nb);
	std::cout << "list:" << resL->val <<std::endl;
	return 0;
}
