/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:28:38 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/29 19:08:57 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
	_name = std::string();
}

Zombie::~Zombie() {
	std::cout << _name << " was destroyed!" << std::endl;
}

void Zombie::setName(const std::string name) {
	this->_name = name;
}

void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}