#include "Array.hpp"
#include "Array.tpp"

int	main(void)
{
	Array<int> *array = new Array<int>(2);

	std::cout << (*array).size() << std::endl;

	array->_array[0] = 0;
	array->_array[1] = 1;

	std::cout << "0:\t" << array[0] << std::endl;
	std::cout << "1:\t" << array[1] << std::endl;

	delete array;
}
