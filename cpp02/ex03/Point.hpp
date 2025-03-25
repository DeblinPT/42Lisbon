/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:05:17 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/14 16:53:49 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	Fixed const _x;
	Fixed const _y;

public:
	Point();
	Point(const float fx, const float fy);
	Point(const Point &other);
	~Point();
	Point &operator=(const Point &other);
	const Fixed &getX(void) const;
	const Fixed &getY(void) const;
};

#endif