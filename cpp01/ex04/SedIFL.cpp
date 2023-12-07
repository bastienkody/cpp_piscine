#include "SedIFL.hpp"
#include "main.hpp"

/*	type bool bc it checks if whole infile fits into a string	*/
bool	SedIFL::infileSizing()
{
	_infile.seekg(0, std::ios_base::end);						// tete lecture last char
	_infileSize = static_cast<unsigned long>(_infile.tellg());	// Fetch the offset
	_infile.seekg(std::ios_base::beg); 							// tete de lecture back to 1st char

	std::string string;
	if (_infileSize >= string.max_size())
		return (false);
	return (true);
}

std::string	SedIFL::outfileNaming(const std::string Filename, const std::string ReplaceExtension)
{
	return (Filename + ReplaceExtension);
}

std::string		SedIFL::doReplacement(const std::string input, const std::string s1, const std::string s2)
{
	std::string		output;
	unsigned long	start = 0;
	unsigned long	found;

	// find return 'npos' if no match
	while ((found = input.find(s1, start)) != std::string::npos)
	{
		// append input to output until s1
		output += input.substr(start, found - start);
		// add s2 in place of s1 in output
		output += s2;
		// update tete de lecture via skipping s1 in input
		start = found + s1.length();
	}
	return (output + input.substr(start));
}

/*	ret false for any init pb (err msg thrown in here)	*/
bool	SedIFL::init(const std::string Filename, const std::string ReplaceExtension)
{
	_infile.open(Filename);
	if (_infile.fail())
		return (std::cout << INFILE_PB << std::endl, false);
	if (infileSizing() == false)
		return (std::cout << FILE_TOO_BIG << std::endl, false);

	_outfile.open(outfileNaming(Filename, ReplaceExtension), std::ios::out | std::ios::trunc);
	if (_outfile.fail())
		return (std::cout << OUTFILE_PB << std::endl, false);
	
	return (true);
}

/*	Could I stack alloc inString bc we checked fileSize < string.max() ; but VLA	*/
void	SedIFL::run(const std::string s1, const std::string s2)
{
	char	*inString = new char [_infileSize];

	if (_infileSize > 0 && _infile.read((inString), _infileSize))
			_outfile << doReplacement(inString, s1, s2);
	delete [] inString;
	_infile.close();
	_outfile.close();
}


