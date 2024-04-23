#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include<iostream>
#include<string>
#include <stack>

/*
	CONSTURCTORS:
		- Default : should i call std::stack() ?  
			->  priori pas besoin
		- Copy : use of operator (does nothing) in copy constr 
			-> it must copy the underlying container. 
			-> can be simply accessed via "mutant.stack"
		- param : can be a problem since i dont define one : can it use the one of stack ?
*/

template <typename T>
class MutantStack:	public std::stack<T>
{
	public:

		MutantStack()	{};
		~MutantStack()	{};
		MutantStack(const MutantStack<T> & src)
		{
			*this = src;
		};
		MutantStack & operator=(__attribute__((unused))const MutantStack<T> & rhs)
		{
			this->c = rhs.c;
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator 				begin()			{ return this->c.begin(); }
		iterator 				end()			{ return this->c.end(); }
		const_iterator			begin() const	{ return this->c.begin(); }
		const_iterator			end() const		{ return this->c.end(); }
		reverse_iterator		rbegin()		{ return this->c.rbegin(); }
		reverse_iterator		rend()			{ return this->c.rend(); }
		const_reverse_iterator	rbegin(void) const { return (this->c.rbegin()); };
		const_reverse_iterator	rend(void) const { return (this->c.rend()); };
};

#endif
