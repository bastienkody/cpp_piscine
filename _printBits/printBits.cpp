#include<iostream>
#include<iomanip>
#include<string>
#include<limits>

/*	FLOAT BITS REPRESENTATION
	1 sign bit S - 8 exponant bits E - 23 mantissa bits M
	0.00000000.00000000000000000000000
	The number it represent is found via the formula : 
	(-1)^s * 2^(128 - E) * M
	There are normnalize and denormalized numbers
	The exponant is bias : it permits to differ from normalized, to store 0,
	infinity and nan
*/

void	printFloatBits(__attribute__((unused)) const float & f)
{
	size_t				len = sizeof(f) * 8;
	const unsigned char	*raw = reinterpret_cast<const unsigned char *>(&f);

	std::cout << "float: " << std::fixed << std::left << std::setw(15) << f << ":\t";
	for (int i = static_cast<int>(len) - 1; i >= 0; --i)
	{
		std::cout << (((raw[i / 8]) >> (i % 8)) & 1);
		if (i == static_cast<int>(len) -1 || i == static_cast<int>(len) -1 - 8)
			std::cout << '.';
	}
	std::cout << std::endl;
}

void	printFloatBits2(__attribute__((unused)) const float & f)
{
	size_t				len = sizeof(f) * 8;

	std::cout << "float2: " << std::left << std::setw(5) << f << ":\t";
	for (int i = static_cast<int>(len) - 1; i >= 0; --i)
	{
		std::cout << (((reinterpret_cast<const unsigned int *>(&f)[0]) >> i) & 1);
		if (i == static_cast<int>(len) -1 || i == static_cast<int>(len) - 1 - 8)
			std::cout << '.';
	}
	std::cout << std::endl;
}


void	printDoubleBits(__attribute__((unused)) const double & d)
{
	size_t				len = sizeof(d) * 8;
	const unsigned char	*raw = reinterpret_cast<const unsigned char *>(&d);

	std::cout << "double: " << std::scientific << std::left << std::setw(15) << d << ":\t";
	for (int i = static_cast<int>(len) - 1; i >= 0; --i)
	{
		std::cout << (((raw[i / 8]) >> (i % 8)) & 1);
		if (i == static_cast<int>(len) -1 || i == static_cast<int>(len) -1 - 11)
			std::cout << '.';
	}
	std::cout << std::endl;
}

void	printIntBits(__attribute__((unused)) const int & i)
{
	size_t	len = sizeof(i) * 8;

	std::cout << "int: " << std::left << std::setw(15) << i << ":\t";
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
