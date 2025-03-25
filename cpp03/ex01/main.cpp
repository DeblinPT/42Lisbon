/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:47:39 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/17 16:55:55 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap e;
	std::cout << std::endl;
	ScavTrap f("Me", false);
	std::cout << std::endl;
	ScavTrap g(e);
	std::cout << std::endl;
	ScavTrap h("You", true);
	std::cout << std::endl;

	e.attack(f.getName());
	f.takeDamage(SCAV_DAMAGE);
	std::cout << std::endl;

	f.attack(e.getName());
	e.takeDamage(SCAV_DAMAGE);
	h.beRepaired(SCAV_DAMAGE);
	std::cout << std::endl;

	f.attack(h.getName());
	h.takeDamage(SCAV_DAMAGE);
	e.beRepaired(10);
	std::cout << std::endl;

	f.attack(h.getName());
	h.takeDamage(SCAV_DAMAGE);
	std::cout << std::endl;
	
	for (int i = 0; i < 50; i++)
	{
		e.guardGate();
		f.guardGate();
		g.guardGate();
		h.guardGate();
		std::cout << std::endl;
	}
	return (0);
}