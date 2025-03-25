/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:56:12 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/14 19:13:48 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c;
	Fixed d;

	c = 10;
	d = 19.10f;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min( d, c ) << std::endl;

	std::cout << "d = " << d.toFloat() << std::endl;
	std::cout << "c = " << c.toFloat() << std::endl;

	std::cout << d + c << std::endl;
	std::cout << d - c << std::endl;
	std::cout << d * c << std::endl;
	std::cout << d / c << std::endl;
	return (0);
}