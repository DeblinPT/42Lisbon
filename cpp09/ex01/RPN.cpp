#include "RPN.hpp"

RPN::RPN() {
//	std::cout << "RPN STD constructor called" << std::endl;
}

RPN::RPN(const RPN &copy) {
//	std::cout << "RPN COPY constructor called" << std::endl;
	*this = copy;
}

RPN::~RPN() {
//	std::cout << "RPN destructor called" << std::endl;
}

RPN	&RPN::operator=(const RPN& other) {
//	std::cout << "RPN ASSIGNMENT operator called" << std::endl;
	if (this != &other)
		_stack = other._stack;
	return *this;
}

void	RPN::exec(std::string input) {
	checkInput(input);
	for (int i = 0; input[i]; i++) {
		if (isspace(input[i]))
			continue;
		else if (isdigit(input[i])) {
			if (input[i + 1] && input[i + 1] != ' ')
				throw errorPrint("A space is required in between arguments");
			_stack.push(atof(input.substr(i, 1).c_str()));
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
			if (input[i + 1] && input[i + 1] != ' ')
				throw errorPrint("A space is required in between arguments");
			doOp(input[i]);
		}
	}
	if (_stack.size() != 1)
		throw errorPrint("operator is missing, can't do calculation");
	std::cout << _stack.top() << std::endl;
}

void	RPN::checkInput(std::string input) {
	for (int i = 0; input[i]; i++) {
		if (!isdigit(input[i]) && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != ' ')
			throw errorPrint("Invalid input only numbers from 0 to 9, +, -, * and /");
		else if (isdigit(input[i]) && input[i + 1] && isdigit(input[i + 1]))
			throw errorPrint("Invalid input only numbers from 0 to 9");
	}
}

void	RPN::doOp(char op) {
	float	first;
	float	second;
	float	res;

	if (_stack.size() < 2)
		throw errorPrint("number is missing, can't do calculation");
	second = _stack.top();
	_stack.pop();
	first = _stack.top();
	_stack.pop();
	switch (op)
	{
	case '+':
		res = first + second;
		_stack.push(res);
		break;
	
	case '-':
		res = first - second;
		_stack.push(res);
		break;

	case '*':
		res = first * second;
		_stack.push(res);
		break;

	case '/':
		res = first / second;
		_stack.push(res);
		break;
	}
}

errorPrint::errorPrint(std::string msg) : std::runtime_error("Error: " + msg) {}
