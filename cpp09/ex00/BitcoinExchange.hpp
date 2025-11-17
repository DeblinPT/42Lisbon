#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>
#include <algorithm>

class btcExch {
		std::map<std::string, float>	_dataBase;
		std::ifstream					_inFileFD;

	public:
		btcExch();
		btcExch(const btcExch&);
		~btcExch();
		btcExch	&operator=(const btcExch&);
		void	loadExchangeData();
		void	loadFile(char*);
		void	checkFormat(std::string);
		void	checkDate(std::string);
		void	checkValue(std::string);
		void	convert(std::string, float);
		void	checkYear(std::string);
		void	checkMonth(std::string);
		void	checkDay(std::string, int, int);
		int		getDBYear(std::map<std::string, float>::iterator);
		int		getDBMonth(std::map<std::string, float>::iterator);
		int		getDBDay(std::map<std::string, float>::iterator);
		std::string		getDataBYear(std::map<std::string, float>::iterator);
		std::string		getDataBMonth(std::map<std::string, float>::iterator);
		std::string		getDataBDay(std::map<std::string, float>::iterator);
};

class errorPrint : public std::runtime_error {
	public:
		errorPrint(std::string msg);
};