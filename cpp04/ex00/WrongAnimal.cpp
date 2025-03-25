/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:30:04 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/20 16:32:08 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("A WrongAnimal") {
	std::cout << "WrongAnimal constructor called" << std::endl;
};

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	*this = copy;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
};

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
	if (this != &copy)
	{
		this->type = copy.type;
	}
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	return (*this);
};

void WrongAnimal::makeSound() const {
	std::cout << "This WrongAnimal is confused and doesn't know what sound to make." << std::endl;
};

std::string WrongAnimal::getType(void) const {
	return (this->type);
};