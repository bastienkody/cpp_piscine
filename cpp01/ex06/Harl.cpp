#include "Harl.hpp"

/*	debug level member function	*/
void	Harl::debug(void) {std::cout << DEBUG_M << std::endl;}
void	Harl::info(void) {std::cout << INFO_M << std::endl;}
void	Harl::warning(void) {std::cout << WARNING_M << std::endl;}
void	Harl::error(void) {std::cout << ERROR_M << std::endl;}

/*	constructor	*/
Harl::Harl()
{
	array[0] = &Harl::debug;
	array[1] = &Harl::info;
	array[2] = &Harl::warning;
	array[3] = &Harl::error;
}

void	Harl::cascade_complain(std::string level)
{
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "unrecognized level"};

	int	i = 0;
	for (; i < 5; i++)
		if (level.compare(levels[i]) == 0)
			break;
	switch (i)
	{
		case 0:
			std::cout << "[ "<< levels[0] << " ]" << std::endl;
			(this->*array[0])();
			std::cout << std::endl;
		case 1:
			std::cout << "[ "<< levels[1] << " ]" << std::endl;
			(this->*array[1])();
			std::cout << std::endl;
		case 2:
			std::cout << "[ "<< levels[2] << " ]" << std::endl;
			(this->*array[2])();
			std::cout << std::endl;
		case 3:
			std::cout << "[ "<< levels[3] << " ]" << std::endl;
			(this->*array[3])();
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

/*	note :
	- no break for case 0 to 2 in order to cascade
	- a break in case 3 not to print default
*/