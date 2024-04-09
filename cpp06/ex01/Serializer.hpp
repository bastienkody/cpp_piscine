#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include<iostream>
#include<string>
#include<stdint.h>


struct Data
{
	std::string value;
	int			nb;
};

class Serializer
{
	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:

		Serializer();
		~Serializer();
		Serializer(const Serializer & src);
		Serializer & operator=(__attribute__((unused))const Serializer & rhs);
};

#endif
