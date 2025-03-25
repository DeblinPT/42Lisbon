/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:25:59 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/18 18:21:43 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource default constructor called" << std::endl;
	_mat = NULL;
};

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource default destructor called" << std::endl;
	delete _mat;
};

MateriaSource::MateriaSource(MateriaSource const &copy) : _mat(copy._mat) {
	std::cout << "MateriaSource copy constructor called" << std::endl;
};

MateriaSource &MateriaSource::operator=(MateriaSource &other) {
	std::cout << "MateriaSource copy assignment operator called" << std::endl;
	if (this != &other)
		_mat = other._mat;
	return *this;
};

void MateriaSource::learnMateria(AMateria* AM) {
	if (!AM) {
		std::cout << "There's no AMateria to learn." << std::endl;
		return;
	}
	else {
		_mat  = AM;
		std::cout << "Learned " << AM->getType() << std::endl;
	}
};

AMateria *MateriaSource::createMateria(std::string const &type) {
	if (_mat->getType() == type) {
		std::cout << "Created " << _mat->getType() << std::endl;
		return (_mat->clone());
	}
	std::cout << "That AMateria type is unknown" << std::endl;
	return (NULL);
};