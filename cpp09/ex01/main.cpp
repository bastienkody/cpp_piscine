#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return std::cout << "Please provide RPN data into a single argument" << std::endl, 2;

	try {
		RPN	rpn(av[1]);
		//rpn.printStack();
		rpn.calculate();
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

}