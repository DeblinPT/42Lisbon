/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:28:30 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/29 18:35:15 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void) {
	Zombie *zumbi;

	zumbi = newZombie("ZuZu");
	zumbi->announce();
	randomChump("ZaZa");
	delete zumbi;
	return (0);
}