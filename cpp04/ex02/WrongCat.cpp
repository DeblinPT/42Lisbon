/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:27:50 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/20 16:30:39 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
};

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
};

WrongCat::WrongCat(const WrongCat &copy) {
	*this = copy;
	std::cout << "WrongCat copy constructor called" << std::endl;
};

WrongCat &WrongCat::operator=(const WrongCat &copy) {
	if (this != &copy)
	{
		this->type = copy.type;
	}
	std::cout << "WrongCat assignment operator called" << std::endl;
	return (*this);
};

void WrongCat::makeSound() const {
	std::cout << this->getType() << " makes the sound: Cockadoodledoo" << std::endl;
};