#include<iostream>
#include<fstream>
#include<string>
#define SEP "##################################################################"

void	printSep(){std::cout << SEP << std::endl;}

//	failbit on
void failbitSolo()
{
	std::ifstream	_infile;

	_infile.open("Unexisting");
	if (_infile.fail())
		std::cout << "failbit on" << std::endl;
	else
		std::cout << "failbit off" << std::endl;
}

//	no exception thrown
void	failbitSoloException()
{
	std::ifstream	_infile;

	try
	{
		_infile.open("Unexisting");
		std::cout << "after open" << std::endl;
	}
	catch(const std::exception& e)
	{ std::cerr << e.what() << '\n'; }
}

// err msg pb + abort on mac os intel
void	failbitAddException()
{
	std::ifstream	_infile;

	try
	{
		_infile.open("Unexisting");
		_infile.exceptions(std::fstream::failbit);
		std::cout << "after open" << std::endl;
	}
	catch(const std::exception& e)
	{ std::cerr << e.what() << '\n'; }
}

int	main(void)
{
	if (true)	{ failbitSolo(); printSep(); }
	if (true)	{ failbitSoloException(); printSep(); }
	if (false)	{ failbitAddException(); printSep(); }
}