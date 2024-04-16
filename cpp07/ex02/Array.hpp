#ifndef ARRAY_HPP
#define ARRAY_HPP

#define SEP "##########################################################"

#include<iostream>
#include<string>
#include<cstdlib>

template<typename T>
class Array
{
	public:
		Array();
		~Array();
		Array(const unsigned int n);
		Array(const Array & src);
		Array & operator=(const Array & rhs);
		T &	operator[](unsigned int index) const;

		class BadIndex: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		unsigned int	size() const;

	private:
		T				*_array;
		unsigned int	_size;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T> &rhs);

#endif
