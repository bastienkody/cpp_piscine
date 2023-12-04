#include "main.hpp"

std::string	outfileName(std::string infile)
{
	return (infile + ".replace");
}


int	main(int ac, char **av)
{
	//arg error
	if (ac != 4)
		return (std::cout << BAR_ARG_NB << std::endl, 1);
	// infile stream
	std::ifstream	inStream(FILENAME);
	if (inStream.fail())
		return (std::cout << INFILE_PB << std::endl, NULL);
	// outfile stream
	std::ofstream	outStream(outfileName(FILENAME), std::ios::out | std::ios::trunc);
	if (outStream.fail())
		return (std::cout << INFILE_PB << std::endl, NULL);

	// read, replace, and write
	std::string	inString;
	std::string	outString;
	while (!inStream.eof())
	{
		std::getline(inStream, inString);
		std::cout << "line read :" << inString << std::endl;
		outString = inString; // replacement in here
		outStream << outString;
	}
	inStream.close();
	outStream.close();
	return (0);
}
