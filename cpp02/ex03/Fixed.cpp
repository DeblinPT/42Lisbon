/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:56:09 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/14 18:23:19 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	_fpNbr = 0;
//	std::cout << "Constructor called." << std::endl;
};

Fixed::Fixed(const Fixed &other) : _fpNbr(other._fpNbr) {
//	std::cout << "Copy constructor called." << std::endl;
};

Fixed::Fixed(const int other) {
//	std::cout << "Constructor (int) called." << std::endl;
	_fpNbr = other << _bits;
};

Fixed::Fixed(const float other) {
//	std::cout << "Constructor (float) called." << std::endl;
	_fpNbr = (int)roundf(other * (1 << _bits));
};

Fixed::~Fixed() {
//	std::cout << "Destructor called." << std::endl;
};

Fixed  &Fixed::operator=(const Fixed &other) {
//	std::cout << "Copy assignment operator overload called." << std::endl;
	if (this != &other)
		_fpNbr = other.getRawBits();
	return (*this);
};

bool Fixed::operator>(const Fixed &other) const {
	return (getRawBits() > other.getRawBits());
};

bool Fixed::operator<(const Fixed &other) const {
	return (getRawBits() < other.getRawBits());
};

bool Fixed::operator>=(const Fixed &other) const {
	return (getRawBits() >= other.getRawBits());
};

bool Fixed::operator<=(const Fixed &other) const {
	return (getRawBits() <= other.getRawBits());
};

bool Fixed::operator==(const Fixed &other) const {
	return (getRawBits() == other.getRawBits());
};

bool Fixed::operator!=(const Fixed &other) const {
	return (getRawBits() != other.getRawBits());
};

Fixed Fixed::operator+(const Fixed &other) const {
	return (toFloat() + other.toFloat());
};

Fixed Fixed::operator-(const Fixed &other) const {
	return (toFloat() - other.toFloat());
};

Fixed Fixed::operator*(const Fixed &other) const {
//	Fixed result;
//	result.setRawBits(getRawBits() * (other.getRawBits() >> _bits));
	return (Fixed(toFloat() * other.toFloat()));
};

Fixed Fixed::operator/(const Fixed &other) const {
	if (!other.getRawBits()) {
		std::cout << "It's not possible to divide by 0!" << std::endl;
		return (Fixed());
	}
	else
		return (Fixed(toFloat() / other.toFloat()));
};

Fixed &Fixed::operator++() {
	++_fpNbr;
	return (*this);
};

Fixed &Fixed::operator--() {
	--_fpNbr;
	return (*this);
};

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++_fpNbr;
	return (temp);
};

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--_fpNbr;
	return (temp);
};

int Fixed::getRawBits(void) const {
//	std::cout << "getRawBits funcion called." << std::endl;
	return (_fpNbr);
};

void Fixed::setRawBits(int const raw) {
//	std::cout << "setRawBits funcion called." << std::endl;
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

Fixed &Fixed::min(Fixed &nbrA, Fixed &nbrB) {
	return (nbrA < nbrB ? nbrA : nbrB);
};

Fixed &Fixed::max(Fixed &nbrA, Fixed &nbrB) {
	return (nbrA > nbrB ? nbrA : nbrB);
};

const Fixed &Fixed::min(const Fixed &nbrA, const Fixed &nbrB) {
	return (nbrA.getRawBits() < nbrB.getRawBits() ? nbrA : nbrB);
};

const Fixed &Fixed::max(const Fixed &nbrA, const Fixed &nbrB) {
	return (nbrA.getRawBits() > nbrB.getRawBits() ? nbrA : nbrB);
};
