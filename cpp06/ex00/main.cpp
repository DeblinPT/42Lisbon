/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:50:13 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/14 18:10:49 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
		const std::string input = av[1];
		ScalarConverter::convert(input);
	}
	else
		std::cerr << "Incorrect input. Please use ./Scalar <value>" << std::endl;
}