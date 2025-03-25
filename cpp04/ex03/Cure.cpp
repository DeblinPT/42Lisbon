/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:22:09 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/19 17:16:12 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure default constructor called" << std::endl;
};

Cure::~Cure() {
	std::cout << "Cure default destructor called" << std::endl;
};

Cure::Cure(const Cure &copy) : AMateria("cure") {
	std::cout << "Cure copy constructor called" << std::endl;
	*this = copy;
};

Cure &Cure::operator=(const Cure &other) {
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return (*this);
};

Cure *Cure::clone() const {
	Cure	*clone = new Cure(*this);
	return (clone);
};

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
};