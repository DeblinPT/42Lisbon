/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:30:05 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/31 20:47:14 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void) {

	{
		weapon club = weapon("crude spiked club");
		humanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		weapon club = weapon("crude spiked club");
		humanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		humanB jack("Jack");
		jack.attack();
		weapon gun("pistol");
		jack.setWeapon(gun);
		jack.attack();
	}
	return (0);
}