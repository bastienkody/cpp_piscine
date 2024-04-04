#include <iostream>
#include <string>
#include <limits>

//	prototypes
void	printFloatBits(__attribute__((unused)) const float & f);
void	printDoubleBits(__attribute__((unused)) const double & d);
void	printIntBits(__attribute__((unused)) const int & i);
void	printCharBits(__attribute__((unused)) const char & c);

//	zero - max - min
void	zeroMaxMin(void)
{
	printCharBits(0);
	printCharBits(std::numeric_limits<char>::min());
	printCharBits(std::numeric_limits<char>::max());

	printIntBits(0);
	printIntBits(std::numeric_limits<signed int>::min());
	printIntBits(std::numeric_limits<signed int>::max());
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


int	main(void)
{
	if (false)	charAmplitude();
	if (true)	intAmplitude();
	if (false)	zeroMaxMin();
}