/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:05:26 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/04 21:25:32 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
	harl _harl;

	if (ac <= 1)
		std::cout << "Harl has nothing to complain about. Maybe you should find a Karen!" << std::endl;
	else {
		for(int i = 1; av[i]; i++) {
			_harl.complain(av[i]);
		}
	}
	return 0;
}