#pragma once

#include <stack>
#include <iostream>
#include <string>
#include <cstdlib>

class RPN {
		std::stack<float>	_stack;

	public:
		RPN();
		RPN(const RPN &);
		~RPN();
		RPN		&operator=(const RPN&);
		void	exec(std::string);
		void	checkInput(std::string);
		void	doOp(char);
};

class errorPrint : public std::runtime_error {
	public:
		errorPrint(std::string msg);
};