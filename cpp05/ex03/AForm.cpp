/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:28:16 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/07 17:00:33 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _sign_grade(150), _exec_grade(150)  {
	std::cout << "AForm STD constructor called" << std::endl;
}

AForm::AForm(std::string name) : _name(name), _signed(false), _sign_grade(150), _exec_grade(150) {
	std::cout << "AForm constructor with NAME called" << std::endl;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	std::cout << "AForm constructor with ALL ARGS called" << std::endl;
	if (this->getSignGrade() > 150 || this->getExecGrade() > 150)
		throw AForm::GradeTooLowException();
	else if (this->getSignGrade() < 1 || this->getExecGrade() < 1) {
		throw AForm::GradeTooHighException();
	}
}

AForm::AForm(AForm const &copy) : _name(copy._name), _signed(copy._signed), _sign_grade(copy._sign_grade), _exec_grade(copy._exec_grade) {
	std::cout << "AForm COPY constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &other) {
	std::cout << "AForm ASSIGNMENT operator called" << std::endl;
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

std::string AForm::getName() {
	return this->_name;
}

int AForm::getSignGrade() {
	return this->_sign_grade;
}

int AForm::getExecGrade() {
	return this->_exec_grade;
}

bool AForm::isSigned() {
	return this->_signed;
}

void AForm::beSigned(Bureaucrat &worker) {
	if (worker.getGrade() <= this->getSignGrade() && this->isSigned() == false)
		_signed = true;
	else if (this->isSigned() == true)
		throw AForm::AlreadySigned();
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const {
	if (_signed == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > _exec_grade)
		throw GradeTooLowException();
	else
		executeForm();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("This Bureaucrat's grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("This Bureaucrat's grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("This form is not signed.");
}

const char *AForm::AlreadySigned::what() const throw() {
	return ("This Form was already signed.");
}

std::ostream &operator<<(std::ostream &out, AForm &AForm) {
	out << AForm.getName() << ", AForm signed: " << AForm.isSigned() << std::endl;
	out << AForm.getName() << ", AForm grade to sign: " << AForm.getSignGrade() << std::endl;
	out << AForm.getExecGrade() << ", AForm grade to execute: " << AForm.getExecGrade() << std::endl;
	return out;
}