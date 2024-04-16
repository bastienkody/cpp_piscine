#ifndef SPAN_HPP
#define SPAN_HPP

#include<iostream>
#include<string>
#include<vector>

class Span
{
	public:

		~Span();
		Span(const unsigned int n);

		void	addNumber(const int nb);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

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

	private:

		// unusable constructors
		Span();
		Span(const Span & src);
		Span & operator=(const Span & rhs);

		std::vector<int>	_vect;
		unsigned int		_max;

};

std::ostream& operator<<(std::ostream& os, const Span &rhs);

#endif
