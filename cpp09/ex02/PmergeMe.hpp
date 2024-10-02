#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include<iostream>
#include<iterator>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

///////////////////////////////////////////////////////////////////////////////
/*	STRUCT NB	*/
struct nb{
	int		val;						// the number value
	bool	is_greatest_from_pair;		// a or b from pair
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

///////////////////////////////////////////////////////////////////////////////
/*	TEMPLATES	*/
// pair comp in place (set greatest), stored in std::pair, set index-1 for odd element
template <typename T, typename U>
void	pairing(T & cont, U & Pair)
{
	typename T::iterator it, next;
	for (it = cont.begin(); it != cont.end(); std::advance(it, 2))
	{
		next = it;
		++next;
		if (next == cont.end()) // last element unpaired
		{
			it->is_greatest_from_pair = false;
			it->index = -1;
			break;
		}
		if (comp(*it, *next) == true)
		{
			it->is_greatest_from_pair = true;
			next->is_greatest_from_pair = false;
			Pair.push_back(std::pair<nb, nb>(*it, *next));
		}
		else
		{
			it->is_greatest_from_pair = false;
			next->is_greatest_from_pair = true;
			Pair.push_back(std::pair<nb, nb>(*next, *it));
		}
	}
}

// no use of T<std::pair> bc it does not hold the odd element (cont does)
// should be done in pairing?
template <typename T>
void	separate_pairs(T &cont, T &M, T &P)
{
	typename T::const_iterator it;
	for (it = cont.begin(); it != cont.end(); std::advance(it, 1))
	{
		if (it->is_greatest_from_pair == true)
			M.push_back(*it);
		else
			P.push_back(*it);
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
void	insert_P_in_M(T &M, T &P)
{
	int index = 0, max_index = M.size() - 1;
	typename T::iterator itP, pos;

	// first index of P always at beginning of M (no comp needed)
	itP = find_index(P, 0);
	M.insert(M.begin(), *itP);
	P.erase(itP);

	// index from 1 to max index (jacob groups later)
	while (++index <= max_index)
	{
		itP = find_index(P, index);
		pos = std::upper_bound(M.begin(), find_index(M, index), *itP);
		M.insert(pos, *itP);
		P.erase(itP);
	}

	// remaining odd element in P
	if (P.size() > 0)
	{
		pos = std::upper_bound(M.begin(), find_index(M, index), *P.begin());
		M.insert(pos, *P.begin());
		P.erase(itP);
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
		std::cout<<it->val<<"\t-->\tgret:"<<it->is_greatest_from_pair<<" index:"<<it->index<<std::endl;
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
	
		std::vector<struct nb>	fja(std::vector<struct nb> vec);
		
	private:
		std::vector<struct nb>	_vec;
		std::list<struct nb>	_lst;
		
		
};

#endif
