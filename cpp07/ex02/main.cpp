#include "Array.hpp"
#include "Array.tpp"
#include "Test.hpp"

int	main(void)
{
	//	int array
	Array<int> array(2);
	std::cout << "size:\t" << array.size() << std::endl;

	array[0] = 0;
	array[1] = 1;

	std::cout << "0:\t" << array[0] << std::endl;
	std::cout << "1:\t" << array[1] << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	//	test array
	Array<Test> test(3);
	std::cout << "size:\t" << array.size() << std::endl;

	std::cout << "0:\t" << test[0] << std::endl;

	test[0].setNb(42);
	test[0].setName("Joe");

	std::cout << "0:\t" << test[0] << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;

	// copy construct (test3) and operator (test2)
	Array<Test> test2(15);
	test2 = test;
	Array<Test> test3(test);

	std::cout  << "size test2:\t" << test2.size() << std::endl;
	std::cout  << "size test3:\t" << test3.size() << std::endl;

	test2[0].setNb(-42);
	test2[0].setName("Oej");

	test3[0].setNb(1234567);
	test3[0].setName("blabla");
 
	std::cout << "test[0]:\t" << test[0] << std::endl;
	std::cout << "test2[0]:\t" << test2[0] << std::endl;
	std::cout << "test3[0]:\t" << test3[0] << std::endl;
}
