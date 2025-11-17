#include "BitcoinExchange.hpp"

btcExch::btcExch() {
//	std::cout << "btcExch STD constructor called" << std::endl;
}

btcExch::btcExch(const btcExch& copy) {
//	std::cout << "btcExch COPY constructor called" << std::endl;
	*this = copy;
}

btcExch::~btcExch() {
//	std::cout << "btcExch destructor called" << std::endl;
}

btcExch	&btcExch::operator=(const btcExch& other) {
//	std::cout << "btcExch ASSIGNMENT operator called" << std::endl;
	if (this != &other) {
		_dataBase = other._dataBase;
	}
	return *this;
}

void	btcExch::loadExchangeData() {
	std::ifstream	db;
	std::string		dbName = "data.csv";
	std::string		buffer;

	db.open(dbName.c_str());
	if (db.is_open()) {
		getline(db, buffer);
		while (getline(db, buffer))
			this->_dataBase[buffer.substr(0, 10)] = strtof(buffer.substr(11).c_str(), NULL);
		db.close();
	}
	else {
		throw errorPrint("opening file");
	}
}

void	btcExch::loadFile(char* av) {
	std::string buf;

	this->_inFileFD.open(av);
	if (_inFileFD.is_open()) {
		getline(_inFileFD, buf);
		if(buf != "date | value") {
			_inFileFD.close();
			throw errorPrint("invalid format of input file");
		}
		while (getline(_inFileFD, buf)) {
			try {
				checkFormat(buf);
				checkDate(buf.substr(0, 10));
				checkValue(buf.substr(13));
				convert(buf.substr(0, 10), strtof(buf.substr(13).c_str(), NULL));
			}
			catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
		_inFileFD.close();
	}
	else
		throw errorPrint("opening file");
}

void	btcExch::checkFormat(std::string str) {
	if (str.substr(10, 3) != " | ")
		throw errorPrint("input does not have the right format => " + str.substr(0, 10));
}

void	btcExch::checkDate(std::string date) {
	if (date[4] != '-' || date[7] != '-')
		throw errorPrint("date in input does not have the right format => " + date);
	std::string	year = date.substr(0, 4);
	std::string	month = date.substr(5, 2);
	std::string	day = date.substr(8, 2);
	checkYear(year);
	checkMonth(month);
	checkDay(day, atoi(month.c_str()), atoi(year.c_str()));
}

void	btcExch::checkValue(std::string value) {
	float	n = atof(value.c_str());

	if (value[0] == '+' || value[0] == '.')
		throw errorPrint("unexpected value input");
	else if (value[0] == '-')
		throw errorPrint("not a positive number");
	for (unsigned long i = 0; i < value.length(); i++) {
		if (!isdigit(value[i]) && value[i] != '.')
			throw errorPrint("unexpected value input");
	}
	if (value[value.length() - 1] == '.' || std::count(value.begin(), value.end(), '.') > 1)
		throw errorPrint("unexpected value input");
	if (n > 1000) 
		throw errorPrint("input value too big");
	else if (n < 0)
		throw errorPrint("input value too small");
}

void	btcExch::convert(std::string date, float value) {
	std::map<std::string, float>::iterator it;
	it = _dataBase.find(date);
	if (it == _dataBase.end()) {
		it = _dataBase.upper_bound(date);
		if (it != _dataBase.begin())
			it--;
	}
	std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
}

void	btcExch::checkYear(std::string year) {
	int	n = atoi(year.c_str());

	if (n < 1 || year.length() > 4)
		throw errorPrint("unexpected year input");
	if (n < getDBYear(this->_dataBase.begin()))
		throw errorPrint("data base starts in the year " + getDataBYear(_dataBase.begin()));
}

void	btcExch::checkMonth(std::string month) {
	int	n = atoi(month.c_str());

	if (!(n >= 1 && n <= 12) || month.length() != 2)
		throw errorPrint("unexpected month input");
	if (n < getDBMonth(this->_dataBase.begin()))
		throw errorPrint("data base starts in " + getDataBYear(_dataBase.begin()) + "-" +getDataBMonth(_dataBase.begin()));
}

void	btcExch::checkDay(std::string day, int month, int year) {
	int	n = atoi(day.c_str());

	if (!(n >= 1 && n <= 31) || day.length() != 2)
		throw errorPrint("unexpected day input");
	if ((month == 4 || month == 6 || month == 9 || month == 11) && n > 30)
		throw errorPrint("unexpected day input");
	if (month == 2) {
		bool	leapY = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (leapY && n > 29)
			throw errorPrint("unexpected day input");
		else if (n > 28)
			throw errorPrint("unexpected day input");
	}
	if (n < getDBDay(this->_dataBase.begin()))
		throw errorPrint("data base starts in " + getDataBYear(_dataBase.begin()) + "-" + getDataBMonth(_dataBase.begin()) + "-" + getDataBDay(_dataBase.begin()));
}

int		btcExch::getDBYear(std::map<std::string, float>::iterator it) {
	if (it == this->_dataBase.end())
		it--;
	return (atoi(it->first.substr(0, 4).c_str()));
}

int		btcExch::getDBMonth(std::map<std::string, float>::iterator it) {
	if (it == this->_dataBase.end())
		it--;
	return (atoi(it->first.substr(5, 2).c_str()));
}

int		btcExch::getDBDay(std::map<std::string, float>::iterator it) {
	if (it == this->_dataBase.end())
		it--;
	return (atoi(it->first.substr(8, 2).c_str()));
}

std::string		btcExch::getDataBYear(std::map<std::string, float>::iterator it) {
	if (it == this->_dataBase.end())
		it--;
	return (it->first.substr(0, 4));
}

std::string		btcExch::getDataBMonth(std::map<std::string, float>::iterator it) {
	if (it == this->_dataBase.end())
		it--;
	return (it->first.substr(5, 2));
}

std::string		btcExch::getDataBDay(std::map<std::string, float>::iterator it) {
	if (it == this->_dataBase.end())
		it--;
	return (it->first.substr(8, 2));
}

errorPrint::errorPrint(std::string msg) : std::runtime_error("Error: " + msg) {}
