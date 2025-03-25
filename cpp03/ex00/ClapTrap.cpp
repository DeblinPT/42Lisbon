/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:27:20 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/17 14:57:45 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()  : _name("Default"), _hitPoints(HP), _energy(ENERGY), _damage(DAMAGE) {
	std::cout << "ClapTrap constructor called" << std::endl;
};

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(HP), _energy(ENERGY), _damage(DAMAGE) {
	std::cout << "ClapTrap constructor with args called" << std::endl;
};

ClapTrap::ClapTrap(ClapTrap const &other)  : _name(other._name), 
	_hitPoints(other._hitPoints), _energy(other._energy), _damage(other._damage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
};

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
};

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energy = other._energy;
		_damage = other._damage;
	}
	std::cout << "ClapTrap assignment operator called" << std::endl;
	return (*this);
};

void ClapTrap::attack(const std::string& target) {
	if (_energy > 0 && _hitPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " attacked " << target << " and caused " << _damage << " of damage." << std::endl;
		_energy--;
	}
	else if (_energy == 0) {
		std::cout << "ClapTrap " << this->_name << " doesn't have enough energy to attack." << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_name << " doesn't have enough hit points to attack." << std::endl;
	}
};

void ClapTrap::takeDamage(unsigned int amount) {
	bool dead = false;
	if (this->_hitPoints == 0)
		dead = true;
	if (this->_hitPoints > amount) {
		_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " was damaged in " << amount << " hit points." << std::endl;
	}
	else if (this->_hitPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " was damaged in " << _hitPoints << " hit points." << std::endl;
		_hitPoints = 0;
		dead = true;
	}
	else if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead, it was just a muscle spasm." << std::endl;
	}
	std::cout << "ClapTrap " << this->_name << " has " << this->_hitPoints << " hit points left." << std::endl;
	if (dead == true) {
		std::cout << "ClapTrap " << this->_name << " died." << std::endl;
	}
};

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy > 0 && _hitPoints > 0) {
		std::cout << "ClapTrap " << this->_name << " was healed in " << amount << std::endl;
		_hitPoints += amount;
		_energy--;
	}
	else if (_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " can't be brought back from the dead." << std::endl;
	}
	else {
		std::cout << "ClapTrap " << this->_name << " doesn't have enough energy." << std::endl;
	}
};
