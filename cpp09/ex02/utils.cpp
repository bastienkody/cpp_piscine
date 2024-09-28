#include "PmergeMe.hpp"
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

