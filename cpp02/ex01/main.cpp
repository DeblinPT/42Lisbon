/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:56:12 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/11 22:19:43 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as a integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as a integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as a integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as a integer" << std::endl;
	std::cout << "a is " << a.toFloat() << " as a float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as a float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as a float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as a float" << std::endl;
return 0;
}