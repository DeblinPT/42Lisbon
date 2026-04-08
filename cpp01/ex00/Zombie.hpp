/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:28:42 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/29 18:29:20 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
		std::string _name;

	public:
		Zombie();
		~Zombie();
		void announce(void);
		void setName(std::string name);
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif