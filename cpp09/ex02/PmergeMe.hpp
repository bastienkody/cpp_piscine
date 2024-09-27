#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>

// prototypes utils
int		conv_to_int(std::string entry);
void	pairing(std::vector<struct nb> &vec);
void	print_lst(std::list<struct nb> lst);
void	print_vec(std::vector<struct nb> vec);

struct nb{
	int		val;					// the number value 
	bool	is_greateast_from_pair;	// a or b from pair
	int		index;					// pair index
	unsigned long int		pair_id;	// pair id to retrieve its peer

	bool operator==(const nb &rhs) const;
	bool operator>(const nb &rhs) const;
	bool operator<(const nb &rhs) const;
};

typedef struct nb nb;

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
