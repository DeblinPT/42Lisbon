/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:21:23 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/18 18:03:10 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		~Cure();
		Cure(Cure const &copy);
		Cure &operator=(Cure const &other);
		Cure *clone() const;
		void use(ICharacter &target);
};