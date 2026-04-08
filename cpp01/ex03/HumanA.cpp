/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 20:03:43 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/30 21:18:24 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

humanA::humanA(std::string name, weapon &newWeapon) : _weapon(newWeapon), _name(name) {};

void humanA::attack(void) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
};