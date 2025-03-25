/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:17:37 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/20 16:14:15 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
};

Cat::~Cat()  {
	std::cout << "Cat destructor called" << std::endl;
};

Cat::Cat(const Cat &copy) : Animal(){
	*this = copy;
	std::cout << "Cat copy constructor called" << std::endl;
};

Cat &Cat::operator=(const Cat &copy) {
	if (this != &copy)
	{
		this->type = copy.type;
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return (*this);
};

void Cat::makeSound() const {
	std::cout << this->getType() << " makes the sound: Meeeeooww." << std::endl;
};