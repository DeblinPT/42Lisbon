/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:30:52 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/30 21:26:31 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class humanA
{
		weapon		&_weapon;
		std::string _name;

	public:
		humanA(std::string name, weapon &newWeapon);
		void attack();

};

#endif