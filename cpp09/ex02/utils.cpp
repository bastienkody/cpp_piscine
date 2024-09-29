#include "PmergeMe.hpp"
#include <algorithm>
#include <iterator>
#include <sstream>

int	conv_to_int(std::string entry)
{
	std::stringstream	sstr(entry);
	int			res;

	sstr >> res;
	if (sstr.fail() || sstr.eof() == false || res < 0)
		throw std::invalid_argument("Bad input: " + entry);
	return res;
}

bool	comp(const nb & a, const nb & b)
{
	//std::cout << "Comp:"<<a.val<<" > "<<b.val<<std::endl;
	return a > b;
}

std::vector<struct nb>::iterator	binary_search(std::vector<nb>::iterator first, std::vector<nb>::iterator last, const struct nb &val)
{
	return std::upper_bound(first, last, val);
}
