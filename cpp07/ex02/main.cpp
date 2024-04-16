#include "Array.hpp"
#include "Array.tpp"
#include "Test.hpp"

void	printSepDouble(){std::cout<<SEP<<std::endl<<SEP<<std::endl;}

/*	Custom main	*/
void	mainCustom(void)
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
	std::cout << "-----------------------------------------------" << std::endl;

	try {std::cout << "test[-1]:\t" << test[-1] << std::endl;}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	try {std::cout << "test2[-45]:\t" << test2[-45] << std::endl;}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	try {std::cout << "test3[34]:\t" << test3[34] << std::endl;}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
}



//	Main sujet
#define MAX_VAL 750
void mainSujetFT(void)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return ;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;
}

int	main(void)
{
	if (true) {mainSujetFT(); printSepDouble();}
	if (true) {mainCustom(); printSepDouble();}
}
