#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

/*
	CONSTURCTORS:
		- Default : should i call std::stack() ?
		- Copy : use of operator (does nothing) in copy constr. is it ok? does it copy?
		- Param : la size init le container ss jacent : should i explciity do/call it ?
*/

template <typename T>
MutantStack<T>::MutantStack() {}
template <typename T>
MutantStack<T>::~MutantStack() {}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> & src)	{ *this = src; }
template <typename T>
MutantStack<T> & MutantStack<T>::operator=(__attribute__((unused))const MutantStack<T> & rhs)	{ return (*this); }


#endif
