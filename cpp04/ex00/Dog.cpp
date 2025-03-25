/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:17:31 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/20 16:14:13 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
};

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
};

Dog::Dog(const Dog &copy) {
	*this = copy;
	std::cout << "Dog copy constructor called" << std::endl;
};

Dog &Dog::operator=(const Dog &copy) {
	if (this != &copy)
	{
		this->type = copy.type;
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return (*this);
};

void Dog::makeSound() const {
	std::cout << this->getType() << " makes the sound: woof, woof." << std::endl;
};