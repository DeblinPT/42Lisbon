#include "RPN.hpp"

int	main(int ac, char** av) {
	if (ac != 2)
		std::cerr << "Invalid number of arguments" << std::endl;

	try {
		RPN rpn;
		rpn.exec(av[1]);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}