/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:48:40 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/03 19:46:17 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int main (int ac, char **av) {
	if (ac != 4) {
		std::cout << "Invalid input." << std::endl;
		return 1;
	}
	else {
		replace(av);
	}
	return 0;
}