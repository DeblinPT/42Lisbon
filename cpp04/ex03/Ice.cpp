/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:29:40 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/18 18:01:02 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice default constructor called" << std::endl;
};

Ice::~Ice() {
	std::cout << "Ice default destructor called" << std::endl;
};

Ice::Ice(const Ice &copy) : AMateria("ice") {
	std::cout << "Ice copy constructor called" << std::endl;
	*this = copy;
};

Ice &Ice::operator=(const Ice &other) {
	std::cout << "Ice assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
};

Ice *Ice::clone() const {
	Ice	*clone = new Ice(*this);
	return (clone);
};

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
};