/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:21:39 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/14 19:11:26 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {

	{
	const Point a;
	const Point b(10, 0);
	const Point c(0, 10);
	const Point point(1, 1);

	std::cout << "Is the point P inside the triangle?" << std::endl;
	std::cout << "P (x = " << point.getX() << "	y = " << point.getY() << ")" << std::endl;
	std::cout << "a (x = " << a.getX() << "	y = " << a.getY() << ")" << std::endl;
	std::cout << "b (x = " << b.getX() << "	y = " << b.getY() << ")" << std::endl;
	std::cout << "c (x = " << c.getX() << "	y = " << c.getY() << ")" << std::endl << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
	}
	std::cout << std::endl;
	{
	Point a(-1.5, -1.5);
	Point b(2.5, 2.5);
	Point c(-1, -2);
	Point point(8.5, -9);

	std::cout << "Is the point P inside the triangle?" << std::endl;
	std::cout << "P (x = " << point.getX() << "	y = " << point.getY() << ")" << std::endl;
	std::cout << "a (x = " << a.getX() << "	y = " << a.getY() << ")" << std::endl;
	std::cout << "b (x = " << b.getX() << "	y = " << b.getY() << ")" << std::endl;
	std::cout << "c (x = " << c.getX() << "	y = " << c.getY() << ")" << std::endl << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
	}
	std::cout << std::endl;
	{
	Point a(-5, -5);
	Point b(5, 5);
	Point c(-5, 5);
	Point point(-5, -5);

	std::cout << "Is the point P inside the triangle?" << std::endl;
	std::cout << "P (x = " << point.getX() << "	y = " << point.getY() << ")" << std::endl;
	std::cout << "a (x = " << a.getX() << "	y = " << a.getY() << ")" << std::endl;
	std::cout << "b (x = " << b.getX() << "	y = " << b.getY() << ")" << std::endl;
	std::cout << "c (x = " << c.getX() << "	y = " << c.getY() << ")" << std::endl << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
	}
	std::cout << std::endl;
	{
		Point a(-5, -5);
		Point b(5, 5);
		Point c(-5, 5);
		Point point(0, 0);
	
		std::cout << "Is the point P inside the triangle?" << std::endl;
		std::cout << "P (x = " << point.getX() << "	y = " << point.getY() << ")" << std::endl;
		std::cout << "a (x = " << a.getX() << "	y = " << a.getY() << ")" << std::endl;
		std::cout << "b (x = " << b.getX() << "	y = " << b.getY() << ")" << std::endl;
		std::cout << "c (x = " << c.getX() << "	y = " << c.getY() << ")" << std::endl << std::endl;
		if (bsp(a, b, c, point) == true)
			std::cout << "\033[32mTRUE\033[0m" << std::endl;
		else
			std::cout << "\033[31mFALSE\033[0m" << std::endl;
		}
	std::cout << std::endl;
	return 0;
}