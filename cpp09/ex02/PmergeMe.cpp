#include"PmergeMe.hpp"

bool  nb::operator==(const nb &rhs) const
{
	return this->val == rhs.val;
}
bool  nb::operator>(const nb &rhs) const
{
	return this->val > rhs.val;
}
bool  nb::operator<(const nb &rhs) const
{
	return this->val < rhs.val;
}


///////////////////////////////////////////////////////////////////////////////////////
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe & src) {*this = src;}
PmergeMe & PmergeMe::operator=(const PmergeMe & rhs)
{
	if(this != &rhs)
	{
		_vec = rhs.getVec();
	}
	return (*this);
}
std::vector<struct nb> const & PmergeMe::getVec() const {return (_vec);}
void PmergeMe::add_to_vec(struct nb nb)
{
	if (std::find(_vec.begin(), _vec.end(), nb) != _vec.end())
		throw std::invalid_argument("Duplicate found");
	_vec.push_back(nb);
}
///////////////////////////////////////////////////////////////////////////////////////

