/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:09:44 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/05 11:36:40 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 75, 45), _target(target) {
	std::cout << "RobotomyRequestForm STD constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy) {
	std::cout << "RobotomyRequestForm COPY constructor called" << std::endl;
	*this = copy;	
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;

}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
	std::cout << "RobotomyRequestForm ASSIGNMENT operator called" << std::endl;
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::executeForm() const {
	int num = rand();
	std::cout << "whirrrrrrr" << std::endl;
	sleep(2);
	std::cout << "thump, thump, thump" << std::endl;
	sleep(2);
	std::cout << "buzzzZZZzzz" << std::endl;
	sleep(2);
	if (num % 2 == 0)
		std::cout << _target << " has been robotomized" << std::endl;
	else
		throw RobotomyRequestFail();
}

const char *RobotomyRequestForm::RobotomyRequestFail::what() const throw() {
	return ("The robotomy failed!");
}