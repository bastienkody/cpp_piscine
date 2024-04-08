#include"Serializer.hpp"

//	Default constructor
Serializer::Serializer() {}

//	Default destructor
Serializer::~Serializer() {}

//	Copy constructor (via copy operator)
Serializer::Serializer(const Serializer & src)
{ *this = src; }

//	Copy operator
Serializer & Serializer::operator=(__attribute__((unused))const Serializer & rhs)
{ return (*this); }

//	static 
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data * Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

