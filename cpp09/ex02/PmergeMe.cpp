#include"PmergeMe.hpp"
#include <iterator>

///////////////////////////////////////////////////////////////////////////////////////
// struct nb operator redefinition
bool  nb::operator==(const nb &rhs) const
{	return this->val == rhs.val;	}
bool  nb::operator>(const nb &rhs) const
{	return this->val > rhs.val;	}
bool  nb::operator<(const nb &rhs) const
{	return this->val < rhs.val;	}
///////////////////////////////////////////////////////////////////////////////////////
// default copleien
PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe & src) {*this = src;}
PmergeMe & PmergeMe::operator=(const PmergeMe & rhs)
{
	if(this != &rhs)
	{
		_vec = rhs.getVec();
		_lst = rhs.getLst();
	}
	return (*this);
}
///////////////////////////////////////////////////////////////////////////////////////
// vector function
std::vector<struct nb> const &	PmergeMe::getVec() const {return (_vec);}
std::vector<struct nb> &		PmergeMe::getVecMod(){return (_vec);}
void PmergeMe::add_to_vec(struct nb nb)
{
	if (std::find(_vec.begin(), _vec.end(), nb) != _vec.end())
		throw std::invalid_argument("Duplicate found");
	_vec.push_back(nb);
}
///////////////////////////////////////////////////////////////////////////////////////
// list function
std::list<struct nb> const &	PmergeMe::getLst() const {return (_lst);}
std::list<struct nb> &			PmergeMe::getLstMod(){return (_lst);}
void PmergeMe::add_to_lst(struct nb nb)
{
	if (std::find(_lst.begin(), _lst.end(), nb) != _lst.end())
		throw std::invalid_argument("Duplicate found");
	_lst.push_back(nb);
}
///////////////////////////////////////////////////////////////////////////////////////
std::vector<struct nb>	PmergeMe::fja(std::vector<struct nb> vec)
{
	std::vector<struct nb> M, P;
	std::vector< std::pair<struct nb, struct nb> > Pair;

	pairing(vec, Pair);
	separate_pairs(vec, M, P);
//	std::cout << "Before recursion:"<<std::endl;
//	std::cout<<"Main:"<<std::endl; print_cont_detail(M);
//	std::cout<<"Pend:"<<std::endl; print_cont_detail(P);
	if (M.size() > 1)
		M = fja(M);

	update_index(M, P, Pair);

//	std::cout << "Pair:" << std::endl;
//	for (std::vector<std::pair<struct nb, struct nb> >::const_iterator it = Pair.begin(); it != Pair.end(); std::advance(it, 1))
//		std::cout<<it->first.val<< '-'<<it->second.val<< " | ";
//	std::cout << std::endl;
//	std::cout<<"Main:"<<std::endl; print_cont_detail(M);
//	std::cout<<"Pend:"<<std::endl; print_cont_detail(P);

	insert_P_in_M(M, P);

	std::cout<<"After insert in M"<<std::endl<<"Main:"<<std::endl; print_cont_detail(M);
//	std::cout<<"Pend:"<<std::endl; print_cont_detail(P);
	std::cout << "##############################################" << std::endl;

	return M;
}
