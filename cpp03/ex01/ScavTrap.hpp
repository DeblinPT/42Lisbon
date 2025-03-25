/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:57:40 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/17 14:37:24 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#define SCAV_HP 100
#define SCAV_ENERGY 50
#define SCAV_DAMAGE 20

class ScavTrap : public ClapTrap {
		bool _guard;

	public:
		ScavTrap();
		ScavTrap(std::string name, bool gard);
		ScavTrap(ScavTrap const &other);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap const &other);
		void attack(const std::string& target);
		void guardGate();
};