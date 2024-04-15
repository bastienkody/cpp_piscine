#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>

/*
	Return type of the function must be preceded by typename: 
	In C++, when you're dealing with with templates that depend on nested types 
	(like iterator in this case), you need to use the typename keyword to 
	specify that a dependent type is indeed a type. This is necessary because 
	the compiler might not be able to deduce whether something is a type or not
	without explicitly stating it.
	In your example, typename T::iterator is dependent on the template parameter
	T. Without the typename keyword, the compiler might interpret T::iterator as
	a static member variable instead of a type, which would lead to a 
	compilation error.
	So, you use typename to explicitly tell the compiler that T::iterator refers
	to a type within the template parameter T. This is a requirement in C++ when
	dealing with dependent types in templates.
*/

template <typename T>
typename T::iterator	easyfind(T &t, int n)
{
	for (typename T::iterator it = t.begin(); it != t.end(); ++it)
		if (*it == n)
			return it;
	return t.end();
}

template <typename T>
typename T::iterator	easyfindWithStdFind(T &t, int n)
{
	return std::find(t.begin(), t.end(), n);
}

#endif
