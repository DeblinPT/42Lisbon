/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:35:35 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/31 20:00:13 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

weapon::weapon(std::string type) : _type(type) {};

const std::string &weapon::getType(void) {
	return (_type);
};

void weapon::setType(std::string newWeapon) {
	_type = newWeapon;
};