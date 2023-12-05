#include "Harl.hpp"

int	main(void)
{
	Harl				harl;
	const std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	std::cout << "\033[4mInputs : debug -> info -> warning -> error\033[0m" << std::endl;
	harl.complain(levels[0]);
	harl.complain(levels[1]);
	harl.complain(levels[2]);
	harl.complain(levels[3]);

	std::cout << "\033[4mInputs : bad level identifiers\033[0m" << std::endl;
	harl.complain("not a std level");
	harl.complain("");
	harl.complain(levels[0] + "," + levels[1]);
	harl.complain("unrecognized level");
}