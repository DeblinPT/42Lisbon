/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:38:07 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/07 17:21:02 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern STD constructor called" << std::endl;
}

Intern::Intern(Intern const &copy) {
	*this = copy;
	std::cout << "Intern COPY constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &other) {
	std::cout << "Intern ASSIGNMENT operator called" << std::endl;
	(void)other;
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target) {
	std::string names[] = {"PresidentialPardonForm", "PresidentialPardon", "Presidential Pardon", "Pardon", "RobotomyRequestForm", "RobotomyRequest", "Robotomy Request", "Robotomy", "ShrubberyCreationForm", "ShrubberyCreation", "Shrubbery Creation", "Shrubbery"};
	int i = 0;
	while (i < 12 && formName != names[i])
		i++;
	switch (i)
	{
		case 0: case 1: case 2: case 3:
		{
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(target));
			break;
		}
		case 4: case 5: case 6: case 7:
		{
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(target));
			break;
		}
		case 8: case 9: case 10: case 11:
		{
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(target));
			break;
		}
		default:
		{
			std::cout << "That form doesn't exist!!!" << std::endl;
			return (NULL);
			break;
		}
	}
}