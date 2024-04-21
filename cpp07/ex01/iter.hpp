#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


/*
	Template function iter:
	Takes an array, its len, a ptr sur fucntion
	Applies ptr function sur len first elements of array
*/
template <typename T, typename F>
void	iter_bad(T *arr, size_t len, F (*fct)(T&))
{
	if (!arr || !fct)
		return ;
	for (size_t i = 0; i < len; ++i)
		fct((arr[i]));
}

template <typename T, typename F>
void	iter(T *arr, size_t len, F fct)
{
	if (!arr || !fct)
		return ;
	for (size_t i = 0; i < len; ++i)
		fct((arr[i]));
}


/*
	utils termplate functions called by iter as funptr
*/
template <typename T>
void	incr(T &a) { ++a; }

template <typename T>
int	decr(T &a) { --a; return 0; }

template <typename T>
void	print(T &a) { std::cout << a << ' '; }

template <typename T>
void	printEndl(T &a) { std::cout << a << std::endl; }

template <typename T>
void	isUpper(T &a) { std::cout << a << ":\t" << (a >= 'A' && a <= 'Z' ? "true" : "false") << std::endl; }


#endif
