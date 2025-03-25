/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:17:37 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/24 15:08:10 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain("Cat");
};

Cat::~Cat()  {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
};

Cat::Cat(const Cat &copy) : Animal(){
	*this = copy;
	this->_brain = new Brain();
	std::cout << "Cat copy constructor called" << std::endl;
};

Cat &Cat::operator=(const Cat &copy) {
	if (this != &copy){
		this->type = copy.type;
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
};

void Cat::makeSound() const {
	std::cout << this->getType() << " makes the sound: Meeeeooww." << std::endl;
};

void Cat::getIdea() const {
	std::cout << this->type << " had the idea: ";
	this->_brain->getIdea();
};

void Cat::getIdea(int nbr) const {
	if (nbr > 0 && nbr <= 100)
		std::cout << this->type << " had the idea: ";
	this->_brain->getIdea(nbr);
};