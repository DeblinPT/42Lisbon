/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 12:43:00 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/07 16:51:32 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Bureaucrat STD constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {
	std::cout << "Bureaucrat constructor with NAME called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	std::cout << "Bureaucrat constructor with ALL ARGS called" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name), _grade(copy._grade) {
	std::cout << "Bureaucrat COPY constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	std::cout << "Bureaucrat ASSIGNMENT operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_grade = other._grade;
	}
	return *this;
}

std::string Bureaucrat::getName(void) const {
	return _name;
}

int Bureaucrat::getGrade(void) const {
	return _grade;
}

void Bureaucrat::increaseGrade(void) {
	if (this->_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	else {
		_grade--;
		std::cout << this->getName() << " grade increased to " << this->getGrade() << std::endl;
	}
}

void Bureaucrat::decreaseGrade(void) {
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else {
		_grade++;
		std::cout << this->getName() << " grade decreased to " << this->getGrade() << std::endl;
	}
}

void Bureaucrat::signForm(Form &toSign) {
	bool isSigned = toSign.isSigned();
	try {
		toSign.beSigned(*this);
	}
	catch (const std::exception &e) {
		std::cout << this->getName() << " couldn’t sign "<< toSign.getName() << " because " << e.what() << "." << std::endl;
		return;
	}
	if (isSigned == false)
		std::cout << this->getName() << " signed "<< toSign.getName() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("This Bureaucrat's grade is too high!!!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("This Bureaucrat's grade is too low!!!");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}