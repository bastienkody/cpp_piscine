#ifndef SPAN_HPP
#define SPAN_HPP

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <numeric>

/*
	Range of iterator to fulfill _vect: 
	I use parameter overload on:
		- addNumber(int) -> add a single int
		- addNumber(it, ite) -> add a range from it to ite
	Iterators are templated :
		- can be used with any iterator (ie. any iterable ocntainer)
		- must be defined in .hpp

	I add a getter on number for my tests ; it requiered a BadIndexz exception

	Sortestspan : sort, diff, then ret the min of the differences. Note the first
	diff is ko because it does (0 - x0) where x0 is the first element. For any 
	other element X at pos n it does (Xn - Xn+1) : 
	example:  0, 1, 3, 8 --> 0, 1, 2, 5 --> ret 1
	Longestspan : sort, ret (last - first)
*/

class Span
{
	public:

		~Span();
		Span(const unsigned int n);
		Span(const Span & src);
		Span & operator=(const Span & rhs);

		int		getNumber(const uint i) const;
		void	addNumber(const int nb);

		template <typename Iterator>
		void	addNumber(Iterator begin, Iterator end)
		{
			while (begin != end)
			{
				if (_vect.size() < _max)
					_vect.push_back(*begin);
				else
					throw NoSpaceLeft();
				++begin;
			}
		}

		int		shortestSpan() const ;
		int		longestSpan() const ;

		class NoSpaceLeft : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NeedAtLeastTwoValues : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class BadIndex : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:

		// unusable constructors
		Span();

		std::vector<int>	_vect;
		unsigned int		_max;

};

#endif
