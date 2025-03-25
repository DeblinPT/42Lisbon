/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:05:26 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/14 17:15:37 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {};

Point::Point(const float fx, const float fy) : _x(fx), _y(fy) {};

Point::Point(const Point &other) : _x(other._x) , _y(other._y) {};

Point::~Point() {};

Point &Point::operator=(const Point &other) {
	if (this != &other)
		return (*this);
	return (*this);
};

const Fixed &Point::getX(void) const {
	return (_x);
};

const Fixed &Point::getY(void) const {
	return (_y);
};