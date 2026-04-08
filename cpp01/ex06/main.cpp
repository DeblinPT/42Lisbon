/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:02:32 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/05 17:50:44 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
	harl _harl;

	if (ac < 2)
		std::cout << "Harl has nothing to complain about. Maybe you should find a Karen!" << std::endl;
	else if (ac > 2)
		std::cout << "Harl can only complain about one thing at a time. Maybe you should find a Karen!" << std::endl;
	else
		_harl.complain(av[ac - 1]);
	return 0;
}