/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:16:27 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/08 20:18:38 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {

	Bureaucrat *pessoa1 = NULL;
	Bureaucrat *pessoa2 = NULL;
	Bureaucrat *pessoa3 = NULL;

	try {
		pessoa1 = new Bureaucrat();
		std::cout << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception " << e.what() << " caught." << std::endl;
		pessoa1 = NULL;
	}
	try {
		pessoa2 = new Bureaucrat("Eu", 1);
		std::cout << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception " << e.what() << " caught." << std::endl;
		pessoa2 = NULL;
	}
	try {
		pessoa3 = new Bureaucrat("Tu");
		std::cout << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "Exception " << e.what() << " caught." << std::endl;
		pessoa3 = NULL;
	}

	try {
		if (pessoa1) {
			std::cout << "Trying increment " << pessoa1->getName() << "'s grade" << std::endl;
			pessoa1->increaseGrade();
		}
	}
	catch (const std::exception &e) {
		std::cout << "Exception " << e.what() << " caught." << std::endl;
	}
	std::cout << std::endl;

	try {
		if (pessoa2) {
			std::cout << "Trying increment " << pessoa2->getName() << "'s grade" << std::endl;
			pessoa2->increaseGrade();
		}
	}
	catch (const std::exception &e) {
		std::cout << "Exception " << e.what() << " caught." << std::endl;
	}
	std::cout << std::endl;

	try {
		if (pessoa2) {
			std::cout << "Trying increment " << pessoa3->getName() << "'s grade" << std::endl;
			pessoa3->increaseGrade();
		}
	}
	catch (const std::exception &e) {
		std::cout << "Exception " << e.what() << " caught." << std::endl;
	}
	std::cout << std::endl;

	try {
		if (pessoa2) {
			std::cout << "Trying increment" << std::endl;
			pessoa1->decreaseGrade();
		}
	}
	catch (const std::exception &e) {
		std::cout << "Exception " << e.what() << " caught." << std::endl;
	}
	std::cout << std::endl;

	try {
		if (pessoa2) {
			std::cout << "Trying increment" << std::endl;
			pessoa2->decreaseGrade();
		}
	}
	catch (const std::exception &e) {
		std::cout << "Exception " << e.what() << " caught." << std::endl;
	}
	std::cout << std::endl;

	try {
		if (pessoa2) {
			std::cout << "Trying increment" << std::endl;
			pessoa3->decreaseGrade();
		}
	}
	catch (const std::exception &e) {
		std::cout << "Exception " << e.what() << " caught." << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat test("Wrong", -1);
	}
	catch (const std::exception &e) {
		std::cout << "Exception " << e.what() << " caught." << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat test("Wrong", -151);
	}
	catch (const std::exception &e) {
		std::cout << "Exception " << e.what() << " caught." << std::endl;
	}
	std::cout << std::endl;

	delete pessoa1;
	delete pessoa2;
	delete pessoa3;
	return 0;
}