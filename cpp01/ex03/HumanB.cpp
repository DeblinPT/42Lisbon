/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:00:37 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/31 20:39:26 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

humanB::humanB(std::string name) : _name(name) {
	_weapon = NULL;
};

void humanB::attack() {
	if (!this->_weapon)
		std::cout << this->_name << " attacks with their fists" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
};

void humanB::setWeapon(weapon &newWeapon) {
	_weapon = &newWeapon;
};