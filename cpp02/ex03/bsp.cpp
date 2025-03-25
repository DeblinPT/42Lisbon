/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:05:37 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/14 18:34:37 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed getArea(const Point &p1, const Point &p2, const Point &p3) {
	return Fixed(0.5f) * ((p1.getX() * (p2.getY() - p3.getY())) +
						   (p2.getX() * (p3.getY() - p1.getY())) +
						   (p3.getX() * (p1.getY() - p2.getY())));
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed totalArea = getArea(a, b, c).toFloat();
	Fixed area1 = getArea(point, b, c).toFloat();
	Fixed area2 = getArea(a, point, c).toFloat();
	Fixed area3 = getArea(a, b, point).toFloat();

	if ((point.getX() == a.getX() && point.getY() == a.getY()) ||
			(point.getX() == b.getX() && point.getX() == b.getX()) ||
			(point.getX() == c.getX() && point.getX() == c.getX()))
		return (false);
	else if (area1.toFloat() == 0 || area2.toFloat() == 0 || area3.toFloat() == 0)
		return (false);
	return (totalArea == (area1 + area2 + area3)) &&
		   (area1 > Fixed(0)) && (area2 > Fixed(0)) && (area3 > Fixed(0));
};