/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:17:55 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/11 14:53:59 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string type;
		Animal();
	public:
		virtual ~Animal() = 0;
		Animal(const Animal &copy);
		Animal &operator=(const Animal &copy);
		virtual void makeSound() const = 0;
		std::string getType(void) const;
};