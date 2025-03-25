/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:13:21 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/17 17:08:21 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	FragTrap e;
	std::cout << std::endl;
	FragTrap f("Me");
	std::cout << std::endl;
	FragTrap g(e);
	std::cout << std::endl;
	FragTrap h("You");
	std::cout << std::endl;

	e.attack(f.getName());
	f.takeDamage(FRAG_DAMAGE);
	std::cout << std::endl;

	f.attack(e.getName());
	e.takeDamage(FRAG_DAMAGE);
	h.beRepaired(20);
	std::cout << std::endl;

	f.attack(h.getName());
	h.takeDamage(FRAG_DAMAGE);
	e.beRepaired(10);
	std::cout << std::endl;

	f.attack(h.getName());
	std::cout << std::endl;
	
	e.highFivesGuys();
	f.highFivesGuys();
	g.highFivesGuys();
	h.highFivesGuys();
	std::cout << std::endl;
	return (0);
}