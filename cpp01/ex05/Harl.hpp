#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

/*	Harl messages	*/
#define DEBUG_M "Harl's messages might not be the most suitable"
#define INFO_M "Harl's messages are not super interesting"
#define WARNING_M "Harl's messages are not interesting at all, really"
#define ERROR_M "Harl's messages are so stupid I refused to replicate them"

/*	sans le typedef j'y arrive pas c pas normal !!!!	*/
class	Harl
{
	private:
		void		debug(void);
		void		info(void);
		void		warning(void);
		void		error(void);
		void		(Harl::*array[4])(void);
	public:
		Harl();
		void	complain(std::string level);

};

#endif