/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:31:47 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/30 21:19:23 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class humanB
{
		weapon		*_weapon;
		std::string _name;

	public:
		humanB(std::string name);
		void attack();
		void setWeapon(weapon &newWeapon);
};

#endif