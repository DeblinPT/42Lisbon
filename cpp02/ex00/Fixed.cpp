/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:22:47 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/11 15:41:50 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	_fpNbr = 0;
	std::cout << "Constructor called." << std::endl;
};

Fixed::Fixed(const Fixed &other) : _fpNbr(other._fpNbr) {
	std::cout << "Copy constructor called." << std::endl;
};

Fixed::~Fixed() {
	std::cout << "Destructor called." << std::endl;
};

Fixed  &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator overload called." << std::endl;
	if (this != &other)
		_fpNbr = other.getRawBits();
	return (*this);
};

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits funcion called." << std::endl;
	return (_fpNbr);
};

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits funcion called." << std::endl;
	_fpNbr = raw;
};