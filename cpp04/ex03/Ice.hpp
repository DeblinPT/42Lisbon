/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:29:56 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/18 18:09:44 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		~Ice();
		Ice(Ice const &copy);
		Ice &operator=(Ice const &other);
		Ice *clone() const;
		void use(ICharacter &target);
};