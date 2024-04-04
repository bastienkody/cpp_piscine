#include <iostream>
#include <limits>

/*
	Float/double : 
		- min() is a positive number (it shows smallest decimal precision)
		- in C++11 there is lowest() than returns the negative boundary
		- "- max()" should give the same as lowest()
*/
void	print_limits()
{
	std::cout << "CHAR MIN:\t" << static_cast<int>(std::numeric_limits<char>::min()) << std::endl;
	std::cout << "CHAR MAX:\t" << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;

	std::cout << "INT MIN:\t" << std::numeric_limits<int>::min() << std::endl;
	std::cout << "INT MAX:\t" << std::numeric_limits<int>::max() << std::endl;

	std::cout << "FLOAT MIN:\t" << std::fixed << -std::numeric_limits<float>::max() << std::endl;
	std::cout << "FLOAT MAX:\t" << std::fixed << std::numeric_limits<float>::max() << std::endl;
	std::cout << "FLOAT INF:\t" << std::numeric_limits<float>::has_infinity << std::endl;
	std::cout << "FLOAT NAN:\t" << std::numeric_limits<float>::has_quiet_NaN << std::endl;

	std::cout << "DOUBL MIN:\t" << std::fixed << -std::numeric_limits<double>::max() << std::endl;
	std::cout << "DOUBL MAX:\t" << std::fixed << std::numeric_limits<double>::max() << std::endl;
	std::cout << "DOUBL INF:\t" << std::numeric_limits<double>::has_infinity << std::endl;
	std::cout << "DOUBL NAN:\t" << std::numeric_limits<double>::has_quiet_NaN << std::endl;
}

/*
	Behaviour to understand by printing bits
		- accepts big numbers as init without overflows
		- but if number is too big to be perfectly precise -> incrementation fails forever
		ie. float = 2 147 000 000 ; float++ keeps on the same nb. 
		Why? it should incr, (with steps potentially bigger than 1)
*/
void	float_precision_test_INTMAX()
{
	float f = 10000000;

	std::cout<< "FLOAT" << std::endl;
	while (++f < 2147483647)
		std::cout << std::fixed << f - 1 << std::endl;
}

/*	
	Might face the same issue as float but at a way higher level
		- until int_max no pb of size neither precision
*/
void	double_precision_test_INTMAX()
{
	double d = 2147000000;

	std::cout<< "DOUBLE" << std::endl;
	while (d < 2147483647)
		std::cout << std::fixed << ++d - 1 << std::endl;
}

int	main(void)
{
	double_precision_test_INTMAX();
}
