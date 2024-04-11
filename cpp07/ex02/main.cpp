#include "Array.hpp"
#include "Array.tpp"
#include "Test.hpp"

int	main(void)
{
	Array<int> array(2);
	std::cout << "size:\t" << array.size() << std::endl;

	array[0] = 0;
	array[1] = 1;

	std::cout << "0:\t" << array[0] << std::endl;
	std::cout << "1:\t" << array[1] << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;


	Array<Test> test(3);
	std::cout << "size:\t" << array.size() << std::endl;

	std::cout << "0:\t" << test[0] << std::endl;

	test[0].setNb(42);
	test[0].setName("Joe");

	std::cout << "0:\t" << test[0] << std::endl;

}
