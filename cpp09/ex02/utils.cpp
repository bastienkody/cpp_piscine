#include "PmergeMe.hpp"
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

void print_vec(std::vector<struct nb> vec)
{
	std::cout << "Vec:" << std::endl;
	for (std::vector<struct nb>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << it->val << (it + 1 == vec.end() ? "" : " - ");
	std::cout<<std::endl;
}

void print_lst(std::list<struct nb> lst)
{
	std::cout << "Lst:" << std::endl;
	for (std::list<struct nb>::const_iterator it = lst.begin(); it != lst.end(); ++it)
	{
		std::list<struct nb>::const_iterator next = it;
		std::cout << it->val << (++next == lst.end() ? "" : " - ");
	}
	std::cout<<std::endl;
}

bool	comp(const nb & a, const nb & b)
{
	return a > b;
}

// assign pair_id and is_greteast_from_peer
void	pairing(std::vector<struct nb> &vec)
{
	size_t	size_odd = vec.size() % 2 == 0;

	std::cout << size_odd << std::endl;
	
}
