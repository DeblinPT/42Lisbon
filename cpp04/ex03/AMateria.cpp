/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:27:18 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/20 15:20:30 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
	std::cout << "AMateria constructor called" << std::endl;
};

AMateria::~AMateria() {
	std::cout << "AMateria destructor called" << std::endl;
};

AMateria::AMateria(AMateria const &copy) : _type(copy._type) {
	std::cout << "AMateria copy constructor called" << std::endl;
};

AMateria &AMateria::operator=(AMateria &other) {
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return (*this);
};

std::string const & AMateria::getType() const {
	return (_type);
};

void AMateria::use(ICharacter &target) {
	std::cout << "Nothig to use against " << target.getName() << std::endl;
};