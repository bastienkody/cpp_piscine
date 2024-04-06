#include <iostream>
#include <iomanip>
#include <limits>

/*
	Float/double : 
		- min() is a positive number (it shows smallest decimal precision)
		- in C++11 there is lowest() than returns the negative boundary
		- "- max()" should give the same as lowest()
*/
void	print_limits()
{
	float	inff = std::numeric_limits<float>::infinity();
	float	inff_n = -std::numeric_limits<float>::infinity();
	float	nanf = std::numeric_limits<float>::quiet_NaN();
	double	inf = std::numeric_limits<double>::infinity();
	double	inf_n = -std::numeric_limits<double>::infinity();
	double	nan = std::numeric_limits<double>::quiet_NaN();

	std::cout << "CHAR MIN\t:\t" << static_cast<int>(std::numeric_limits<char>::min()) << std::endl;
	std::cout << "CHAR MAX\t:\t" << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;

	std::cout << "INT MIN\t\t:\t" << std::numeric_limits<int>::min() << std::endl;
	std::cout << "INT MAX\t\t:\t" << std::numeric_limits<int>::max() << std::endl;

	std::cout << "FLOAT MIN\t:\t" << std::fixed << std::setprecision(12) << std::numeric_limits<float>::min() << std::endl;
	std::cout << "FLOAT MAX\t:\t" << std::fixed << std::numeric_limits<float>::max() << std::endl;
	std::cout << "FLOAT -MAX\t:\t" << std::fixed << -std::numeric_limits<float>::max() << std::endl;
	std::cout << "FLOAT +INF\t:\t" << std::fixed << inff << std::endl;
	std::cout << "FLOAT -INF\t:\t" << std::fixed << inff_n << std::endl;
	std::cout << "FLOAT NAN\t:\t" << std::fixed << nanf << std::endl;

	std::cout << "DOUBL MIN\t:\t" << std::scientific  << std::numeric_limits<double>::min() << std::endl;
	std::cout << "DOUBL -MAX\t:\t" << std::fixed << -std::numeric_limits<double>::max() << std::endl;
	std::cout << "DOUBL MAX\t:\t" << std::fixed << std::numeric_limits<double>::max() << std::endl;
	std::cout << "DOUBLE +INF\t:\t" << std::fixed << inf << std::endl;
	std::cout << "DOUBLE -INF\t:\t" << std::fixed << inf_n << std::endl;
	std::cout << "DOUBLE NAN\t:\t" << std::fixed << nan << std::endl;
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
	print_limits();
}
