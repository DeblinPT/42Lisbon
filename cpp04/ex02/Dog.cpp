/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:17:31 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/24 15:08:06 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain("Dog");
};

Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
};

Dog::Dog(const Dog &copy) {
	*this = copy;
	this->_brain = new Brain();
	std::cout << "Dog copy constructor called" << std::endl;
};

Dog &Dog::operator=(const Dog &copy) {
	if (this != &copy) {
		this->type = copy.type;
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
};

void Dog::makeSound() const {
	std::cout << this->getType() << " makes the sound: woof, woof." << std::endl;
};

void Dog::getIdea() const {
	std::cout << this->type << " had the idea: ";
	_brain->getIdea();
};

void Dog::getIdea(int nbr) const {
	if (nbr > 0 && nbr <= 100)
		std::cout << this->type << " had the idea: ";
	_brain->getIdea(nbr);
};