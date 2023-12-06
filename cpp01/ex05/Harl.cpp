#include "Harl.hpp"

/*	debug level member function	*/
void	Harl::debug(void) {std::cout << DEBUG_M << std::endl;}
void	Harl::info(void) {std::cout << INFO_M << std::endl;}
void	Harl::warning(void) {std::cout << WARNING_M << std::endl;}
void	Harl::error(void) {std::cout << ERROR_M << std::endl;}

/*	default constructor	*/
Harl::Harl()
{
	array[0] = &Harl::debug;
	array[1] = &Harl::info;
	array[2] = &Harl::warning;
	array[3] = &Harl::error;
}

void	Harl::complain(std::string level)
{
	const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR", "unrecognized level"};

	int	i = 0;
	for (; i < 5; i++)
		if (level.compare(levels[i]) == 0)
			break;
	if (i >= 0 && i < 4)
		(this->*array[i])();
	else
		std::cout << levels[4] << std::endl;
}

