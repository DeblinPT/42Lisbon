/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:16:02 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/17 17:05:00 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main () {
	ClapTrap a;
	std::cout << std::endl;
	ClapTrap b("Bob");
	std::cout << std::endl;
	ClapTrap c("John");
	std::cout << std::endl;
	ClapTrap d(a);
	std::cout << std::endl;

	a.attack("Bob");
	b.takeDamage(0);
	std::cout << std::endl;

	b.attack("Default");
	a.takeDamage(20);
	std::cout << std::endl;
	
	c.beRepaired(20);
	std::cout << std::endl;

	b.attack("John");
	c.takeDamage(20);
	std::cout << std::endl;
	
	a.beRepaired(10);
	std::cout << std::endl;
	
	b.attack("John");
	return (0);
};