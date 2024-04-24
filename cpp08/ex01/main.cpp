#include "Span.hpp"

void	printSep(){std::cout << "##########################################" << std::endl;}

void	mainSujet(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
 
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	exceptionsTests()
{
	Span	span(1);

	try {
		for (uint i = 0; i < 2; ++i)
			span.addNumber(i);
	}
	catch(const std::exception& e)	{std::cerr << e.what() << '\n'; }

	try								{span.getNumber(2);}
	catch(const std::exception& e)	{std::cerr << e.what() << '\n';}

	try								{span.longestSpan();}
	catch(const std::exception& e)	{std::cerr << e.what() << '\n';}

	try								{span.shortestSpan();}
	catch(const std::exception& e)	{std::cerr << e.what() << '\n';}

}

void	addNumberRangeTest()
{
	std::vector<int>	v(5, 102);
	Span			s(5);

	s.addNumber(v.begin(), v.end());

	for (u_int i = 0; i<5; ++i)
		std::cout << s.getNumber(i) << " - ";
	std::cout << std::endl;

}

void	tenThousandsOneNumber()
{
	Span	span(10001);

	for (uint i = 0; i < 10001; ++i)
		span.addNumber(i);
	for (uint i = 0; i < 10001; ++i)
		std::cout << span.getNumber(i) << " - ";
	std::cout << std::endl;

	std::cout << "Shortest:\t" << span.shortestSpan() << std::endl;
	std::cout << "Longest:\t" << span.longestSpan() << std::endl;
}



int	main(void)
{
	if (true) {mainSujet(); printSep();}
	if (true) {tenThousandsOneNumber();printSep();}
	if (true) {exceptionsTests();printSep();}
	if (true) {addNumberRangeTest();printSep();}
}
