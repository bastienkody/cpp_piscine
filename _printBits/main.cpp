#include <iostream>
#include <string>
#include <limits>

//	printBits prototypes
void	printFloatBits(__attribute__((unused)) const float & f);
void	printFloatBits2(__attribute__((unused)) const float & f);
void	printDoubleBits(__attribute__((unused)) const double & d);
void	printIntBits(__attribute__((unused)) const int & i);
void	printCharBits(__attribute__((unused)) const char & c);

//	precision test prototypes
bool	intFloatPreciseEnough(int nb);

//	zero - max - min
void	zeroMaxMin(void)
{
	printCharBits(0);
	printCharBits(std::numeric_limits<char>::min());
	printCharBits(std::numeric_limits<char>::max());

	printIntBits(0);
	printIntBits(std::numeric_limits<signed int>::min());
	printIntBits(std::numeric_limits<signed int>::max());

	printFloatBits(0);
	printFloatBits(std::numeric_limits<float>::min());
	printFloatBits(std::numeric_limits<float>::max());
	printFloatBits(-std::numeric_limits<float>::max());
	printFloatBits(std::numeric_limits<float>::quiet_NaN());
	printFloatBits(std::numeric_limits<float>::infinity());
	printFloatBits(-std::numeric_limits<float>::infinity());

	printDoubleBits(0);
	printDoubleBits(std::numeric_limits<double>::min());
	printDoubleBits(std::numeric_limits<double>::max());
	printDoubleBits(-std::numeric_limits<double>::max());
	printDoubleBits(std::numeric_limits<double>::quiet_NaN());
	printDoubleBits(std::numeric_limits<double>::infinity());
	printDoubleBits(-std::numeric_limits<double>::infinity());
}

//	amplitudes
void	charAmplitude(void)
{
	printCharBits(0);
	printCharBits(1);
	printCharBits(2);
	printCharBits(4);
	printCharBits(8);
	printCharBits(16);
	printCharBits(32);
	printCharBits(64);
	printCharBits(127);
	printCharBits(-1);
	printCharBits(-2);
	printCharBits(-4);
	printCharBits(-8);
	printCharBits(-16);
	printCharBits(-32);
	printCharBits(-64);
	printCharBits(-128);
}

void	intAmplitude(void)
{
	int i = 0;

	printIntBits(i++);
	for (; i > 0; i *= 2)
		printIntBits(i);
	for (; i < 0; i /= 2) 
		printIntBits(i);
}

void	floatAmplitude(void)
{
	float	f = 1;
	while (f < std::numeric_limits<float>::max())
	{
		printFloatBits(f);
		f *= 2;
	}
}

int	main(void)
{
	if (false)	charAmplitude();
	if (false)	intAmplitude();
	if (false)	floatAmplitude();

	if (false)	zeroMaxMin();

	if (true)
	{
		int	tab[] = {8388608, 16777216, 16777217, 16777218, 2147483647};
		for (int i = 0; i < 5; ++i)
			 intFloatPreciseEnough(tab[i]);
	}
}
