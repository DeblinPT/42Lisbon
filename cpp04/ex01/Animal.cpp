/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:17:57 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/21 17:22:34 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("An Animal") {
	std::cout << "Animal constructor called" << std::endl;
};

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
};

Animal::Animal(const Animal &copy) {
	*this = copy;
	std::cout << "Animal copy constructor called" << std::endl;
};

Animal &Animal::operator=(const Animal &copy) {
	if (this != &copy){
		this->type = copy.type;
	}
	std::cout << "Animal assignment operator called" << std::endl;
	return (*this);
};

void Animal::makeSound() const {
	std::cout << "This Animal doesn't make a sound." << std::endl;
};

std::string Animal::getType(void) const {
	return (this->type);
};