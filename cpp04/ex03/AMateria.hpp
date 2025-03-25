/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:27:49 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/20 14:38:08 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class ICharacter;

//Abstract Class!!!
class AMateria {
	protected:
		std::string	_type;
	public:
		AMateria(std::string const & type);
		virtual ~AMateria() = 0;
		AMateria(AMateria const &copy);
		AMateria &operator=(AMateria &other);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};