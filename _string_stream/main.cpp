#include <string>
#include <iostream>
#include <sstream>

/*
	It creates a real file in the current directory

	It takes a string the can be manipulayted as a stream
	Its a stream : when FLUSHED somewhere it gets EMPTY !

	When using for type conversion (ie. ss >> int) :

	Does not THROW ANY EXCEPTION on error type

	Overflow : no, it cuts at max (ie. ss 214748364799999 -> int 2147483647)

	It wont help for cpp06/ex00

	-------------------------------------------------------------------------
	-------------------------------------------------------------------------

	Chat GPT proposed to check failbit and eofbit of my sstream after conv
	- ss.fail() --> false if conv error (dont know how it checks, ovlf seems handled)
	- ss.eof()  --> false if the whole stream data was not flush (ie. 1.f to int
	the ".f" is not flush)
	By checking both bits after flush, we can know if the "conv" was right. 
	Let's try if it works for all inputs

	Can help the parsing
	Good stuff : 
	- int : converts perfectly, failbit if overflow
	Problems : 
	- char : ss outputs in a char but the value is still present in my ss so 
	eofbit check is ko. dont understand why. (i must parse)
	- float : does not accept the trailing 'f' (i must parse)
	- double/float : both seems treated the same
		. missing point is accepted (if i check int its ok)
		. no digit after/before point if ok (i must parse, or let it still), but
			if there is no digit at all (ie. "."), failbit !
		. "nan" is accepted as double and float
		. "+/-inf" is accepted as double or float
		. "+/-inff" is rejected from both

*/

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "one arg please" << std::endl, 1);

	std::string input(argv[1]);
	std::cout << "arg : " << input << std::endl; 

	std::stringstream	ss_int(input);
	std::stringstream	ss_float(input);
	std::stringstream	ss_double(input);
	int		i;
	float	f;
	double	d;

// INT
	ss_int >> i;
	std::cout << "i :\t" << i;
	if (!ss_int.fail() && ss_int.eof())
		std::cout << "\t OK" << std::endl;
	else
	{
		std::cout << "\t KO";
		if (ss_int.fail()) { std::cout << "\tfailtbit"; }
		if (!ss_int.eof()) { std::cout << "\tnot eof, remains:" << ss_int.str(); }
		std::cout << std::endl;
	}

// CHAR
	if (input.size() == 1 && !isdigit(input[0]) && isprint(input[0]))
	{
		char c = input[0];
		std::cout << "d :\tchar '" << c << "'" << std::endl;
	}
	else
		std::cout << "d :\tnot a char" << std::endl;
	
// FLOAT
	ss_float >> f;
	std::cout << "f :\t" << f;
	if (!ss_float.fail() && ss_float.eof())
		std::cout << "\t OK" << std::endl;
	else
	{
		std::cout << "\t KO";
		if (ss_float.fail()) { std::cout << "\tfailtbit"; }
		if (!ss_float.eof()) { std::cout << "\tnot eof, remains:" << ss_float.str(); }
		std::cout << std::endl;
	}

// DOUBLE
	ss_double >> d;
	std::cout << "d :\t" << d;
	if (!ss_double.fail() && ss_double.eof())
		std::cout << "\t OK" << std::endl;
	else
	{
		std::cout << "\t KO";
		if (ss_double.fail()) { std::cout << "\tfailtbit"; }
		if (!ss_double.eof()) { std::cout << "\tnot eof, remains:" << ss_double.str(); }
		std::cout << std::endl;
	}
}