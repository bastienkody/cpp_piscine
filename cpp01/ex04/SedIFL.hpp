#ifndef SEDIFL_HPP
#define SEDIFL_HPP

#include <string>
#include <iostream>
#include <fstream>

/*
on va pas passer par le constructeur car je sais pas comment gerer les cas 
d'erreur depuis, car pas de type de retour et pas envie d'allourdir la classe
de flags genre bool init_infile =1 etc
*/
class	SedIFL
{
	public:
		bool	init(const std::string Filename, const std::string ReplaceExtension);
		void	run(const std::string s1, const std::string s2);
	private:
		std::ifstream	_infile;
		std::ofstream	_outfile;
		unsigned long	_infileSize;
		bool			infileSizing();
		std::string		outfileNaming(const std::string Filename, const std::string ReplaceExtension);
		std::string		doReplacement(const std::string input, const std::string s1, const std::string s2);
};

#endif