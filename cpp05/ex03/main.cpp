/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:53:54 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/08 20:26:33 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void) {

	Intern Joe;
	{
		Intern John = Joe;
	}
	Intern Jane;
	Intern Karen;
	std::cout << std::endl;

	Bureaucrat	President("President", 1);
	Bureaucrat	PrimeMinister("Prime Minister", 45);
	Bureaucrat	Mayor("Mayor", 137);
	Bureaucrat	Default;

	std::cout << "----------------------------------------------------------------------------------" <<std::endl;

	AForm *pardonOne = Karen.makeForm("PresidentialPardonForm", "Elon");
	AForm *pardonTwo = Karen.makeForm("PresidentialPardon", "Trump");
	AForm *pardonThree = Karen.makeForm("Presidential Pardon", "JD");
	AForm *pardonFour = Karen.makeForm("Pardon", "Someone Else");
	std::cout << std::endl;
	AForm *robotomyOne = Jane.makeForm("RobotomyRequestForm", "Terminator1");
	AForm *robotomyTwo = Jane.makeForm("RobotomyRequest", "Terminator2");
	AForm *robotomyThree = Jane.makeForm("Robotomy Request", "Terminator3");
	AForm *robotomyFour = Jane.makeForm("Robotomy", "Terminator4");
	std::cout << std::endl;
	AForm *shrubberyOne = Joe.makeForm("ShrubberyCreationForm", "English Boxwood");
	AForm *shrubberyTwo = Joe.makeForm("ShrubberyCreation", "Cornus");
	AForm *shrubberyThree = Joe.makeForm("Shrubbery Creation", "Angustifolia");
	AForm *shrubberyFour = Joe.makeForm("Shrubbery", "Nightfall");
	std::cout << std::endl;

	Default.signForm(*pardonOne);
	Default.signForm(*robotomyOne);
	Default.signForm(*shrubberyOne);
	std::cout << std::endl;

	Mayor.signForm(*pardonTwo);
	Mayor.signForm(*robotomyTwo);
	Mayor.signForm(*shrubberyTwo);
	std::cout << std::endl;

	PrimeMinister.signForm(*pardonThree);
	PrimeMinister.signForm(*robotomyThree);
	PrimeMinister.signForm(*shrubberyThree);
	std::cout << std::endl;

	President.signForm(*pardonFour);
	President.signForm(*robotomyFour);
	President.signForm(*shrubberyFour);
	std::cout << std::endl;

	delete pardonOne;
	delete pardonTwo;
	delete pardonThree;
	delete pardonFour;
	delete robotomyOne;
	delete robotomyTwo;
	delete robotomyThree;
	delete robotomyFour;
	delete shrubberyOne;
	delete shrubberyTwo;
	delete shrubberyThree;
	delete shrubberyFour;

	AForm* test = Karen.makeForm("lala", "lala");
	if (test)
		President.signForm(*test);

	return 0;
}