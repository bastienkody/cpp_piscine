#include "main.hpp"

/*	create the outfile name	*/
std::string	outfileName(std::string infile) {return (infile + ".replace");}

/*	the real work	*/
std::string	do_replacement(const std::string input, const std::string s1, const std::string s2)
{
	std::string		output;
	unsigned long	start = 0;
	unsigned long	found;

	// find return 'npos' with not found
	while ((found = input.find(s1, start)) != std::string::npos)
	{
		// append input until s1
		output += input.substr(start, found - start);
		// add s2 
		output += s2;
		// tete de lecture input after dernier char de s1
		start = found + s1.length();
	}
	return (output + input.substr(start));
}

/*	buffer len	*/
unsigned long	infilen(std::ifstream& infile)
{
	infile.seekg(0, std::ios_base::end);	// tete lecture dernier char
	unsigned long	size = infile.tellg();	// Get the offset
	infile.seekg(std::ios_base::beg); 		// tete de lecture premier char
	return (size);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << BAR_ARG_NB << std::endl, 1);

	// infile
	std::ifstream	infile(FILENAME);
	if (infile.fail())
		return (std::cout << INFILE_PB << std::endl, 2);
	unsigned long	infile_size = infilen(infile);
	// outfile
	std::ofstream	outfile(outfileName(FILENAME), std::ios::out | std::ios::trunc);
	if (outfile.fail())
		return (std::cout << OUTFILE_PB << std::endl, 3);

	// read, replace, and write
	char	*inString = new char [infile_size];
	if (infile_size > 0)
		while (infile.read((inString), infile_size))
			outfile << do_replacement(inString, S1, S2);

	// outro
	delete [] inString;
	infile.close();
	outfile.close();
	return (0);
}