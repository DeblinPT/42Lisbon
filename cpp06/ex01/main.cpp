/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:49:21 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/15 19:21:38 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <climits>

int main(int ac, char **av) {
	if (ac == 3) {
		std::string number = av[1];
		Data	data;
		long	nbr = atol(av[1]);
		data.text = av[2];

		if (number.empty() || (number.length() > 11 && nbr < std::numeric_limits<int>::min()) || (number.length() > 10 && nbr > std::numeric_limits<int>::max())) {
			std::cerr << "Incorrect input. Please choose a value between -2147483648 and 2147483647" << std::endl;
			return -1;
		}
		else {
			data.value = nbr;
			uintptr_t	raw = Serializer::serialize(&data);
			Data		*copy = Serializer::deserialize(raw);
			if (copy == &data) {
				std::cout << "Pointer matches: Yes" << std::endl;
				std::cout << "Int value: " << copy->value << std::endl;
				std::cout << "Text: " << copy->text << std::endl;
				return 0;
			}
			else {
				std::cerr << "Pointer matches: NO!!" << std::endl;
				return -1;
			}

		}
	}
	else {
		std::cerr << "Incorrect input. Please use ./Serializer <int value> \"<String>\"" << std::endl;
		return -1;
	}
}