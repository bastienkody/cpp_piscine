#include<iostream>
#include<iomanip>
#include<string>
#include<limits>

void	printFloatBits(__attribute__((unused)) float f) 
{
	// needs to be casted before accessing bits

}

void	printDoubleBits(__attribute__((unused)) const double & d)
{
	//size_t	len = sizeof(d) * 8;

}

void	printIntBits(__attribute__((unused)) const int & i)
{
	size_t	len = sizeof(i) * 8;

	std::cout << "int: " << std::left << std::setw(15) << static_cast<int>(i) << ":\t";
	for (int j = static_cast<int>(len) - 1; j >= 0; --j)
	{
		std::cout << ((i >> j) & 1);
		if (j == static_cast<int>(len) - 1)
			std::cout << '.';
	}
	std::cout << std::endl;
}

void	printCharBits(__attribute__((unused))const char & c)
{
	size_t	len = sizeof(c) * 8;

	std::cout << "char: " << std::left << std::setw(5) << static_cast<int>(c) << ":\t";
	for (int i = static_cast<int>(len) - 1; i >= 0; --i)
	{
		std::cout << ((c >> i) & 1);
		if (i == static_cast<int>(len) - 1)
			std::cout << '.';
	}
	std::cout << std::endl;
}