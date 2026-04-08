/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:29:51 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/31 19:57:59 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class weapon
{
		std::string _type;

	public:
		weapon(std::string type);
		const std::string &getType(void);
		void setType(std::string newWeapon);
};

#endif