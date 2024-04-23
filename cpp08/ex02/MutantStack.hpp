#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include<iostream>
#include<string>
#include <stack>


template <typename T>
class MutantStack:	public std::stack<T>
{
	public:

		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack<T> & src);
		MutantStack & operator=(__attribute__((unused))const MutantStack<T> & rhs);

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator 		begin()			{ return this->c.begin(); }
		iterator 		end()			{ return this->c.end(); }
		const_iterator	begin() const	{ return this->c.begin(); }
		const_iterator	end() const		{ return this->c.end(); }
};


#include "MutantStack.tpp"
#endif
