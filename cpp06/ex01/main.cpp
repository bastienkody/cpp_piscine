#include "Serializer.hpp"

int	main(void)
{
	Data	data;
	Data	*dptr = new Data;

	data.value = "salut";
	dptr->value = "ciao";

	std::cout << "\033[4mBefore serialization:\033[m" << std::endl;
	std::cout << "data:\t" << data.value << std::endl;
	std::cout << "addr:\t" << &data << std::endl;
	std::cout << "dptr:\t" << dptr->value << std::endl;
	std::cout << "addr:\t" << dptr << std::endl;

	std::cout << "\033[4mAfter serialization:\033[m" << std::endl;
	std::cout << "data:\t" << Serializer::deserialize(Serializer::serialize(&data))->value << std::endl;
	std::cout << "addr:\t" << Serializer::deserialize(Serializer::serialize(&data))<< std::endl;
	std::cout << "dptr:\t" << Serializer::deserialize(Serializer::serialize(dptr))->value << std::endl;
	std::cout << "addr:\t" << Serializer::deserialize(Serializer::serialize(dptr)) << std::endl;

	delete dptr;
}
