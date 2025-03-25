/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:56:09 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/11 22:16:31 by adimas-d         ###   ########.fr       */
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

Fixed::Fixed(const int other) {
	std::cout << "Constructor (int) called." << std::endl;
	_fpNbr = other << _bits;
};

Fixed::Fixed(const float other) {
	std::cout << "Constructor (float) called." << std::endl;
	_fpNbr = (int)roundf(other * (1 << _bits));
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

float Fixed::toFloat( void ) const {
	return ((float)_fpNbr / (1 << _bits));
};

int Fixed::toInt( void ) const {
	return ((int)_fpNbr >> _bits);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return (out);
};