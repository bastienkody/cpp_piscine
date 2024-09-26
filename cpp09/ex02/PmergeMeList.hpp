#ifndef PMERGEMELIST_HPP
#define PMERGEMELIST_HPP

#include<list>
#include "PmergeMe.hpp"

class PmergeMeList
{
	public:
		PmergeMeList();
		~PmergeMeList();
		PmergeMeList(const PmergeMeList & src);
		PmergeMeList & operator=(const PmergeMeList & rhs);

		std::list<struct nb> const & getLst() const;

		void	add_to_lst(struct nb);
		
	private:
		std::list<struct nb>	_lst;
		
};

#endif
