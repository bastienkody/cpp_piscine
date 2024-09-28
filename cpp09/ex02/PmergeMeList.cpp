#include"PmergeMeList.hpp"

//	Default constructor
PmergeMeList::PmergeMeList() {}
PmergeMeList::~PmergeMeList() {}
//	Copy constructor (via copy operator)
PmergeMeList::PmergeMeList(const PmergeMeList & src) {*this = src;}
//	Copy operator
PmergeMeList & PmergeMeList::operator=(const PmergeMeList & rhs)
{
	if(this != &rhs)
	{
		_lst = rhs.getLst();
	}
	return (*this);
}
std::list<struct nb> const & PmergeMeList::getLst() const {return (_lst);}
std::list<struct nb> & PmergeMeList::getLstMod() {return (_lst);}
void PmergeMeList::add_to_lst(struct nb nb)
{
	if (std::find(_lst.begin(), _lst.end(), nb) != _lst.end())
		throw std::invalid_argument("Duplicate found");
	_lst.push_back(nb);
}

