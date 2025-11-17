/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:15:26 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/10 20:30:52 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter STD constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const&) {
	std::cout << "ScalarConverter COPY constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const&) {
	std::cout << "ScalarConverter ASSIGNMENT operator called" << std::endl;
	return (*this);
}

void ScalarConverter::convert(const std::string &input) {
	size_t	len = input.length();
	int		type = findType(input, len);
	switch (type)
	{
		case 0: {
			printPseuso(input);
			break;
		} //pseudo-literals
		case 1: {
			printInt(input);
			break;
		} //int
		case 2: {
			printChar(input);
			break;
		} //char
		case 3: {
			printDouble(input);
			break;
		} //double
		case 4: {
			printFloat(input);
			break;
		} //float
		default: {
			std::cout << "Invalid input" << std::endl;
			break;
		}
	}
}