/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:35:37 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/29 19:13:44 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie		*horde1;
	int			horde1Nb = 5;
	std::string	hordeName1 = "ZumZum";
	Zombie		*horde2;
	int			horde2Nb = 10;
	std::string	hordeName2 = "BiBi";


	horde1 = zombieHorde(horde1Nb, hordeName1);
	std::cout << "A horde of " << horde1Nb << " zombies named " << hordeName1 << " was created." << std::endl;
	horde2 = zombieHorde(horde2Nb, hordeName2);
	std::cout << "A horde of " << horde2Nb << " zombies named " << hordeName2 << " was created." << std::endl;
	for (int i = 0; i < horde1Nb; i++) {
		std::cout << "Zombie number " << i + 1 << " announces -> ";
		horde1[i].announce();
	}
	for (int i = 0; i < horde2Nb; i++) {
		std::cout << "Zombie number " << i + 1 << " announces -> ";
		horde2[i].announce();
	}
	delete []horde1;
	delete []horde2;
	return (0);
}