#include"PmergeMe.hpp"
#include <sys/time.h>

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
std::vector<struct nb>	PmergeMe::fja_Vec(std::vector<struct nb> vec)
{
	std::vector<struct nb> M, P;
	std::vector< std::pair<struct nb, struct nb> > Pair;

	pairing(vec, M, P, Pair);
	if (M.size() > 1)
		M = fja_Vec(M);
	update_index(M, P, Pair);
/*	std::cout<<"Before insert in M"<<std::endl;
	std::cout << "Pair: ";
	for (std::vector< std::pair<struct nb, struct nb> >::iterator it = Pair.begin(); it != Pair.end(); ++it)
		std::cout << it->first.val << "-" << it->second.val << " | ";
	std::cout << std::endl;
	std::cout << "Main:"<<std::endl; print_cont_detail(M);
	std::cout<<"P:"<<std::endl; print_cont_detail(P);
*/
	insert_P_in_M(M, P);
/*	std::cout<<"After insert in M"<<std::endl<<"Main:"<<std::endl; print_cont_detail(M);
	std::cout<<"P:"<<std::endl; print_cont_detail(P);
	std::cout << "##############################################" << std::endl;
*/
	return M;
}

std::list<struct nb>	PmergeMe::fja_Lst(std::list<struct nb> lst)
{
	std::list<struct nb> M, P;
	std::list< std::pair<struct nb, struct nb> > Pair;

	pairing(lst, M, P, Pair);
	if (M.size() > 1)
		M = fja_Lst(M);
	update_index(M, P, Pair);
/*	std::cout<<"Before insert in M"<<std::endl;
	std::cout << "Pair: ";
	for (std::list< std::pair<struct nb, struct nb> >::iterator it = Pair.begin(); it != Pair.end(); ++it)
		std::cout << it->first.val << "-" << it->second.val << " | ";
	std::cout << std::endl;
	std::cout << "Main:"<<std::endl; print_cont_detail(M);
	std::cout<<"P:"<<std::endl; print_cont_detail(P);
*/
	insert_P_in_M(M, P);
/*	std::cout<<"After insert in M"<<std::endl<<"Main:"<<std::endl; print_cont_detail(M);
	std::cout<<"P:"<<std::endl; print_cont_detail(P);
	std::cout << "##############################################" << std::endl;
*/
	return M;
}

void	PmergeMe::fja()
{
	std::cout << "Input:\t\t\t"; print_cont_val(_vec);

	if (_vec.size() == 1)
	{
		std::cout << "Output:\t\t\t"; print_cont_val(_vec);
		std::cout << "Time to process: none bc no use of algo for one element"<<std::endl;
		return ;
	}

	std::clock_t lsTime, vecTime = std::clock();
	_vec = fja_Vec(_vec);
	vecTime = std::clock() - vecTime;

	lsTime = std::clock();
	_lst = fja_Lst(_lst);
	lsTime = std::clock() - lsTime;

	std::cout << "Output (vector):\t"; print_cont_val(_vec);
	std::cout << "Output (list):\t\t"; print_cont_val(_lst);
	std::cout << "For a range of " << _vec.size() << " elements." << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "CPU time used with std::vector:\t"
			<< 1000.0 * vecTime / CLOCKS_PER_SEC << "ms" << std::endl;
	std::cout << std::fixed << std::setprecision(2) << "CPU time used with std::list:\t"
			<< 1000.0 * lsTime / CLOCKS_PER_SEC << "ms" << std::endl;

}
