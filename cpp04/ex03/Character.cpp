/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:11:56 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/20 15:14:36 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		_inv[i] = NULL;
	}
};

Character::~Character() {
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_inv[i])
			delete _inv[i];
	}
};

Character::Character(Character const &copy) : _name(copy._name) {
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (copy._inv[i])
			_inv[i] = copy._inv[i]->clone();
		else
			_inv[i] = NULL;
	}
};

Character &Character::operator=(Character &other) {
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (_inv[i])
				delete _inv[i];
			if (other._inv[i])
				_inv[i] = other._inv[i]->clone();
			else
				_inv[i] = NULL;
		}
	}
	return (*this);
};

std::string const &Character::getName() const {
	return (this->_name);
};

void Character::equip(AMateria *AM) {
	if (!AM) {
		std::cout << "Cant't equip no AMateria!" << std::endl;
		return;
	}
	int i = 0;
	while (i < 4 && _inv[i])
		i++;
	if (i >= 0 && i <=3){
		_inv[i] = AM;
		std::cout << _name << " equiped " << _inv[i]->getType() << " in slot " << i << std::endl;
	}
	else
		std::cout << "Cant't equip no free space" << std::endl;
};

void Character::unequip(int idx) {
	if (idx <= 0 || idx >= 3)
		std::cout << idx << " is not a valid slot numeber" << std::endl;
	else if (!_inv[idx])
		std::cout << idx << " is empty" << std::endl;
	else {
		std::cout << _inv[idx]->getType() << " was unequipped" << std::endl;
		_inv[idx] = NULL;
	}
};

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= 3)
		std::cout << idx << " is not a valid slot numeber" << std::endl;
	else if (!_inv[idx])
		std::cout << "Inventory slot " << idx << " is empty" << std::endl;
	else {
		std::cout << _name << " ";
		_inv[idx]->use(target);
		_inv[idx] = NULL;
	}
};