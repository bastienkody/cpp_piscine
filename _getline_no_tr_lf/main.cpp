#include <string>
#include <iostream>
#include <fstream>

#define FILE "file"

/*
	Test if getline reads a last line without trailing LF at the end (as gnl)
	--> IT DOES !!
*/

int	main(void)
{
	std::fstream	infile;
	std::string		buf;

	infile.open(FILE, std::ios::in);
	while(getline(infile, buf))
		std::cout << buf << std::endl;
}
