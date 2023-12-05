#ifndef MAIN_HPP
#define MAIN_HPP

#include <string>
#include <iostream>
#include <fstream>

#define FILENAME av[1]
#define S1 av[2]
#define S2 av[3]

#define BAR_ARG_NB "Unexpected number of argument. Usage : ./sed_ifl <filename> <s1> <s2>."
#define INFILE_PB "Could not open infile. Please check file existence and reading rights"
#define OUTFILE_PB "Could not open outfile. Please check writing rights (ls -l; chmod u+w outfile)"
#define FILE_TOO_BIG "The file size is bigger than the std::string.max_size(). The program\
will not be ab le to write anything to the replacement file for conformity and safety reasons"

#endif