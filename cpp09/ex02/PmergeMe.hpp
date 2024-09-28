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
	bool	is_greateast_from_pair;		// a or b from pair
	bool	is_solo;					// a or b from pair
	int		index;						// pair index
	unsigned long int		pair_id;	// pair id to retrieve its peer

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
template <typename T>
void	pairingT(T & cont)
{
	unsigned int	pair_id = 0;

	typename T::iterator it;
	typename T::iterator next;
	for (it = cont.begin(); it != cont.end(); std::advance(it, 2))
	{
		next = it;
		++next;
		it->pair_id = pair_id;
		if (next == cont.end()) // last element unpaired
		{
			it->is_greateast_from_pair = false;
			it->is_solo = true;
			break;
		}
		it->is_solo = false;
		next->is_solo = false;
		next->pair_id = pair_id;
		if (comp(*it, *next) == true)
		{
			it->is_greateast_from_pair = true;
			next->is_greateast_from_pair = false;
		}
		else
		{
			it->is_greateast_from_pair = false;
			next->is_greateast_from_pair = true;
		}
		++pair_id;
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
	typename T::const_iterator it;
	for (it = cont.begin(); it != cont.end(); ++it)
	{
		std::cout<<it->val<<"\t-->\tp_id:"<<it->pair_id<<" gret:"<<it->is_greateast_from_pair<<" solo:"<<it->is_solo<<std::endl;
	}
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

		std::vector<struct nb> const & getVec() const;
		std::vector<struct nb> & getVecMod();

		void	add_to_vec(struct nb);
		
	private:
		std::vector<struct nb>	_vec;
		
		
};

#endif
