#include <iostream>
#include <string>

/*
	PROBLEM : std::string method front(), back(), pop_back() are missing form libcstd 98
	I cant use them at 42, i want to replicate their behaviour

	str.erase() -> take off a (range of) character from a str
*/


void	test1(void)
{
	std::string	str("salut");

	std::cout << "str:\t" << str << std::endl;
	std::cout << "str.back():\t" << str.back() << std::endl;

	str.pop_back();
	std::cout << "str.pop_back():\t" << str << std::endl;
}

void	test2(void)
{
	std::string	str("salut");

	str.erase(str.end() - 1);
	std::cout << "str.erase(str.end() - 1):\t" << str << std::endl;

	str += 't';
	str.erase(str.size() - 1);
	std::cout << "str.erase(str.size() - 1):\t" << str << std::endl;
}

void	test3(void)
{
	std::string	str("salut");

	str.erase(str.find('a'), str.find('u'));
	std::cout << "str.erase(str.find('a'), str.find('u')):\t" << str << std::endl;

	str = "salut";
	str.erase(str.begin() + 1, str.end() - 1);
	std::cout << "str.erase(str.begin() + 1, str.end() - 1):\t" << str << std::endl;

}

int	main(void)
{
	if (true) test1();
	if (true) test2();
	if (true) test3();


}