/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:41:40 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/17 16:41:22 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	std::cout << "--------------DiamondTrap tests--------------" << std::endl;
	{
		DiamondTrap e;
		std::cout << std::endl;
		DiamondTrap f("Me");
		std::cout << std::endl;
		DiamondTrap g(e);
		std::cout << std::endl;
		DiamondTrap h("You");
		std::cout << std::endl;
		DiamondTrap i;
		i = f;

		std::cout << std::endl;
		e.attack(h.getName());
		f.attack(e.getName());
		g.attack(e.getName());
		h.attack(h.getName());
		i.attack(h.getName());
		std::cout << std::endl;
		f.ScavTrap::takeDamage(FRAG_DAMAGE);
		f.ScavTrap::takeDamage(FRAG_DAMAGE);
		f.ScavTrap::takeDamage(FRAG_DAMAGE);
		f.ScavTrap::takeDamage(FRAG_DAMAGE);
		std::cout << std::endl;
		f.ClapTrap::beRepaired(20);
		std::cout << std::endl;
		e.guardGate();
		f.guardGate();
		g.guardGate();
		h.guardGate();
		i.guardGate();
		std::cout << std::endl;
		e.highFivesGuys();
		f.highFivesGuys();
		g.highFivesGuys();
		h.highFivesGuys();
		i.highFivesGuys();
		std::cout << std::endl;
		e.whoAmI();
		f.whoAmI();
		g.whoAmI();
		h.whoAmI();
		i.whoAmI();
		std::cout << std::endl;
	}
	return (0);
}