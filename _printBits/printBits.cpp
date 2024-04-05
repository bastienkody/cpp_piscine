#include<iostream>
#include<iomanip>
#include<string>
#include<limits>
#include<cstdlib>
#include<cmath>

/*	FLOAT BITS REPRESENTATION
	1 sign bit S - 8 exponant bits E - 23 mantissa bits M
	0.00000000.00000000000000000000000
	The number it represent is found via the formula : 
	(-1)^s * 2^(128 - E) * M
	There are normnalize and denormalized numbers
	The exponant is bias : it permits to differ from normalized, to store 0,
	infinity and nan

	Precision :
	source : 
	https://fabiensanglard.net/floating_point_visually_explained/
	https://blog.demofox.org/2017/11/21/floating-point-precision/
	Each range of power of 2 have 2^23 possible precision (size of mantissa).
	The precision step is found by finding the ranges of power of 2 nb is in
	ie. 1,5 -> [1, 2]
	you divide the absolute subtraction of this range by the precision val : 
	abs(2 - 1) / 2^23 <==> 1 / 8388608 =  0.00000011920929
	For info, the lack of precision start to be an interger for the range : 
	[2^23, 2^24] ie. any number > 8388608 can't have decimal (step is 1)
	For the next range [2^24, 2^25], step is 2
	It grows folowing power of 2
	It also degrows in decimal for each "inversed power of 2" (ie : /2)


	I could find a formula that for a given int (string representation)
	would tell if there is enough precision to store it precisely.
	It should 
		0 - if nb is an exact power of 2 : OK
		1 - store absolute val of int into an unsigned u_nb
		2 - find the range of power of 2 (no in decimal such as [0.5, 0.25] since int only)
		3 - calculate the step (abs(r1-r2)/2^23)
		4 - opti : set a flag R, that tells from which born (r1:=1 or r2:=2)
			nb is the closest
		5 - incr/decremant from one born (according to R) by step until you
			reach, or go over, nb. If its nb : precision ok; else : KO
	--> pb for number with a little step which is rounded  (ie. 2 -> step 0.0625)
	which does niot retrieve 2 exactly. I will start at 2^23 ou 24 to find int step only
*/

bool	intFloatPreciseEnough(int nb)
{
	unsigned int	u_nb = std::abs(nb);

	std::cout << "nb\t:\t" << nb << std::endl;
	std::cout << "uabs(nb):\t" << u_nb << std::endl;

	if (nb <= std::pow(2, 24))
	{
		std::cout << "OK (<=2^24):\t" << nb << std::endl;
		std::cout << "#########################################################" << std::endl;
		return true;
	}

	double	r1 = 1;
	double	r2;
	double	step;

	while (r1 * 2 < static_cast<double>(u_nb))
		r1 *= 2;

	r2 = r1 *2;
	step = (r2 - r1) / std::pow(2, 23);
	std::cout << "range\t:\t[ " << std::fixed << std::setprecision(0) << r1 << " - " << std::fixed << std::setprecision(0) << r2 << " ]" << std::endl;
	std::cout << "step\t:\t" << std::fixed << std::setprecision(0) << step << std::endl;

	while (r1 < static_cast<double>(u_nb))
		r1 += step;

	if (r1 == static_cast<double>(u_nb))
	{
		std::cout << "OK\t:\t" << nb << std::endl;
		std::cout << "#########################################################" << std::endl;
		return true;
	}
	else
	{	
		std::cout << "KO\t:\t" << nb << std::endl;
		std::cout << "+/-\t:\t" << std::fixed << std::setprecision(0) << r1 - step << " - " << std::fixed << std::setprecision(0) << r1 << std::endl;
		std::cout << "#########################################################" << std::endl;
		return false;
	}


}



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
