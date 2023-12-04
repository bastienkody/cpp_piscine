#include <iostream>
#include <string>

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "The memory address of the string variable (via &string -> address of a var)\t\t";
	std::cout << &string << std::endl;
	std::cout << "The memory address held by stringPTR (via stringPTR -> address pointed to by a ptr)\t";
	std::cout << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF (via &stringREF -> address pointed to by a ref)\t";
	std::cout << &stringREF << std::endl << std::endl;

	std::cout << "The value of the string variable (via string -> value of a var)\t\t\t";
	std::cout << string << std::endl;
	std::cout << "The value pointed to by stringPTR (via *stringPTR -> value pointed to by a ptr)\t";
	std::cout << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF (via stringREF -> value pointed to by a ref)\t";
	std::cout << stringREF << std::endl;
}
