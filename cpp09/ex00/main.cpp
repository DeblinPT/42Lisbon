#include "BitcoinExchange.hpp"

int main(int ac, char** av) {
	 if (ac != 2) {
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		return 1;
	 }
	 try {
		btcExch exch;
		exch.loadExchangeData();
		exch.loadFile(av[1]);
	 }
	 catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	 }
	 return 0;
}