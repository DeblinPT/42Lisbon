#include "PmergeMe.hpp"

int main (int ac, char** av) {
	if (ac < 2)
		std::cerr << "Error: too few arguments" << std::endl;
	else {
		try {
			PmergeMe data(ac, av);
			data.sort();
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}