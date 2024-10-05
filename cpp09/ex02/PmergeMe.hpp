#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include<iostream>
#include<iterator>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<ctime>
#include<iomanip>

///////////////////////////////////////////////////////////////////////////////
/*	STRUCT NB	*/
struct nb{
	int		val;						// the number value
	int		index;						// pair index (set after depairing)

	bool operator==(const nb &rhs) const;
	bool operator>(const nb &rhs) const;
	bool operator<(const nb &rhs) const;
};
typedef struct nb nb;

///////////////////////////////////////////////////////////////////////////////
/*	UTILS PROTOTYPES	*/
int		conv_to_int(std::string entry);
bool	comp(const nb & a, const nb & b);
int		jacob(int n);

///////////////////////////////////////////////////////////////////////////////
/*	TEMPLATES	*/
// pair comp, stored in Pair (first holds larger), set index-1 for odd element
template <typename T, typename U>
void	pairing(T &cont, T &M, T &P, U &Pair)
{
	typename T::iterator it, next;
	for (it = cont.begin(); it != cont.end(); std::advance(it, 2))
	{
		next = it;
		++next;
		if (next == cont.end()) // last element unpaired
		{
			it->index = -1;
			P.push_back(*it);
			break;
		}
		if (comp(*it, *next) == false)
		{
			M.push_back(*it);
			P.push_back(*next);
			Pair.push_back(std::pair<nb, nb>(*it, *next));
		}
		else
		{
			P.push_back(*it);
			M.push_back(*next);
			Pair.push_back(std::pair<nb, nb>(*next, *it));
		}
	}
}

// indexation in M after sort, retrieve peer in P via Pair to put same index
template <typename T, typename U>
void	update_index(T &M, T &P, U & Pair)
{
	int index = 0;
	typename T::iterator it, itP;
	typename U::iterator pos;
	for (it = M.begin(); it != M.end(); std::advance(it, 1), ++index)
	{
		it->index = index;
		for (pos = Pair.begin(); pos != Pair.end() && pos->first.val != it->val; std::advance(pos, 1));
		for (itP = P.begin(); itP != P.end(); std::advance(itP, 1))
			if (pos->second.val == itP->val)
				itP->index = index;
	}
}

// returns it on struct nb for nb->index == index, else cont.end()
// cant use std::find because struct nb operator== is on nb.val
template <typename T>
typename T::iterator	find_index(T &cont, int index)
{
	typename T::iterator it = cont.begin();
	for (; it != cont.end() && it->index != index; std::advance(it, 1));
	return it;
}

template <typename T>
T	get_next_jacob_group(T &P, int jacob_n, int index)
{
	T	group;
	int size = jacob(jacob_n + 1) - jacob(jacob_n) ;

/*	std::cout << "jacob size: " << size;
	std::cout << ", n: " << jacob_n;
	std::cout << ", index: " << index << std::endl;
*/
	typename T::iterator it = P.begin();
	while (P.size() && size--)
	{
		it = find_index(P, index);
		if (it == P.end())
			it = find_index(P, -1); // odd element
		group.push_back(*it);
		P.erase(it);
		++index;
	}

	//std::cout << "jacob group \n"; print_cont_val(group);
	return group;
}

template <typename T>
void	insert_P_in_M(T &M, T &P)
{
	typename T::iterator itP, itG, pos;
	// first index of P always at beginning of M (no comp needed)
	itP = find_index(P, 0);
//	std::cout << "inserted i0: " << itP->val << std::endl;
	M.insert(M.begin(), *itP);
	P.erase(itP);

	int index = 1;
	int jacob_n = -1;

	T	group;
	typename T::reverse_iterator rbeg;
	while (P.size())
	{
		group = get_next_jacob_group(P, ++jacob_n, index);
		for (rbeg=group.rbegin(); rbeg!=group.rend(); std::advance(rbeg,1))
		{
			if (rbeg->index == -1)
				pos = std::upper_bound(M.begin(), M.end(), *rbeg, comp);
			else
				pos = std::upper_bound(M.begin(), find_index(M, rbeg->index), *rbeg, comp);
			M.insert(pos, *rbeg);
			++index;
		}
	}
}

template <typename T>
void	print_cont_val(T & cont)
{
	typename T::const_iterator it;
	typename T::const_iterator next;
	for (it = cont.begin(); it != cont.end(); ++it)
	{
		next = it; 
		std::cout<< it->val << (++next == cont.end() ? "" : " - ");
	}
	std::cout << std::endl;
}
template <typename T>
void	print_cont_detail(T & cont)
{
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
		std::cout<<it->val<<"\t-->\t"<<" index:"<<it->index<<std::endl;
	std::cout<<"-------------------------"<<std::endl;
}
///////////////////////////////////////////////////////////////////////////////

class PmergeMe
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe & src);
		PmergeMe & operator=(const PmergeMe & rhs);

		std::vector<struct nb> const &	getVec() const;
		std::vector<struct nb> &		getVecMod();
		void							add_to_vec(struct nb);

		std::list<struct nb> const &	getLst() const;
		std::list<struct nb> &			getLstMod();
		void							add_to_lst(struct nb);
	
		std::vector<struct nb>	fja_Vec(std::vector<struct nb> vec);
		std::list<struct nb>	fja_Lst(std::list<struct nb> lst);

		void					fja();
		
	private:
		std::vector<struct nb>	_vec;
		std::list<struct nb>	_lst;
};

#endif
