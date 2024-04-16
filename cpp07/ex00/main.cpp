#include "whatever.hpp"
#include "Test.hpp"

void	printSep() {std::cout << "########################################" << std::endl;}

/*	CUSTOM MAIN with class Test	*/
void	classTest(void)
{
	Test	a = Test(0, "TestA");
	Test	b = Test(0, "TestB");

	std::cout << "a:\t\t" << a <<std::endl;
	std::cout << "b:\t\t" << b <<std::endl;

	// a == b : returns b
	std::cout << "Max(a, b):\t" << ::max(a, b) << std::endl;

	// a.setNb(42)
	std::cout << "\033[3mset a.nb to 42\033[m" << std::endl;
	a.setNb(42);

	std::cout << "Min(b, a):\t" << ::min(b, a) << std::endl;

	// a <=> b
	std::cout << "\033[3mswapping a <=> b\033[m" << std::endl;
	::swap(a, b);

	std::cout << "a:\t\t" << a <<std::endl;
	std::cout << "b:\t\t" << b <<std::endl;


}

//	CUSTOM MAIN with FLOAT
void	withFloat(void)
{
	float	d=0.01, e=0.001;

	std::cout << "d:\t" << d << std::endl;
	std::cout << "e:\t" << e << std::endl;

	std::cout << "max(d, e) = \t" << ::max(d, e) << std::endl;
	std::cout << "min(d, e) = \t" << ::min(d, e) << std::endl;
}


//	MAIN SUJET 42
void mainSujetFT(void)
{
	int a = 2;
	int b = 3;

	::swap( a, b );

	std::cout << "a = " << a << ", b = " << b << std::endl;
	

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);

	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
}

int	main(void)
{
	if (true) {mainSujetFT(); printSep();}
	if (true) {withFloat(); printSep();}
	if (true) {classTest(); printSep();}
}
