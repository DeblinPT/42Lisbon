/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:53:54 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/02 16:51:41 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void) {

	ShrubberyCreationForm test("test");
	ShrubberyCreationForm test1 = test;

	RobotomyRequestForm test3("test");
	RobotomyRequestForm test4 = test3;

	PresidentialPardonForm test5("test");
	PresidentialPardonForm test6 = test5;

	std::cout << "----------------------------------------------------------------------------------" <<std::endl;

	Bureaucrat	President("President", 1);
	Bureaucrat	PrimeMinister("Prime Minister", 45);
	Bureaucrat	Mayor("Mayor", 137);
	Bureaucrat	Default;
	std::cout << std::endl;

	//AForm Random;
	ShrubberyCreationForm	Shrubbery("Shrubbery");
	RobotomyRequestForm		AlexMurphy("Alex Murphy");
	PresidentialPardonForm	Self("Trump");
	std::cout << std::endl;

	srand(time(NULL));

	Default.signForm(Shrubbery);
	Default.signForm(AlexMurphy);
	Default.signForm(Self);
	std::cout << std::endl;

	Default.executeForm(Shrubbery);
	Default.executeForm(AlexMurphy);
	Default.executeForm(Self);
	std::cout << std::endl;

	President.signForm(Self);
	PrimeMinister.signForm(AlexMurphy);
	Mayor.signForm(Shrubbery);
	std::cout << std::endl;

	Mayor.executeForm(Shrubbery);
	Mayor.executeForm(AlexMurphy);
	Mayor.executeForm(Self);
	std::cout << std::endl;

	PrimeMinister.executeForm(AlexMurphy);
	PrimeMinister.executeForm(Self);
	std::cout << std::endl;

	President.executeForm(Self);
	std::cout << std::endl;

	return 0;
}