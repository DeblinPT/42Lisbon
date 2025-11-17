/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:28:16 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/07 17:08:53 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _sign_grade(150), _exec_grade(150)  {
	std::cout << "Form STD constructor called" << std::endl;
}

Form::Form(std::string name) : _name(name), _signed(false), _sign_grade(150), _exec_grade(150) {
	std::cout << "Form constructor with NAME called" << std::endl;
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	std::cout << "Form constructor with ALL ARGS called" << std::endl;
	if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
		throw Form::GradeTooLowException();
	else if (this->getSignGrade() < 1 || this->getExecGrade() < 1) {
		throw Form::GradeTooHighException();
	}
}

Form::Form(Form const &copy) : _name(copy._name), _signed(copy._signed), _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade) {
	std::cout << "Form COPY constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(Form const &other) {
	std::cout << "Form ASSIGNMENT operator called" << std::endl;
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

std::string Form::getName() {
	return this->_name;
}

int Form::getSignGrade() {
	return this->_sign_grade;
}

int Form::getExecGrade() {
	return this->_exec_grade;
}

bool Form::isSigned() {
	return this->_signed;
}

void Form::beSigned(Bureaucrat &worker) {
	if (worker.getGrade() <= this->getSignGrade() && this->isSigned() == false)
		_signed = true;
	else if (this->isSigned() == true)
		std::cout << worker.getName() << " couldn’t sign " << this->getName() << " because it was already signed." << std::endl;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("this Bureaucrat's grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("this Bureaucrat's grade is too low");
}

std::ostream &operator<<(std::ostream &out, Form &form) {
	out << form.getName() << ", form signed: " << form.isSigned() << std::endl;
	out << form.getName() << ", form grade to sign: " << form.getSignGrade() << std::endl;
	out << form.getExecGrade() << ", form grade to execute: " << form.getExecGrade() << std::endl;
	return out;
}