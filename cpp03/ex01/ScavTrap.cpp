/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:57:28 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/17 14:37:12 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->_hitPoints = SCAV_HP;
	this->_energy = SCAV_ENERGY;
	this->_damage = SCAV_DAMAGE;
	this->_guard = false;
	std::cout << "ScavTrap constructor called" << std::endl;
};

ScavTrap::ScavTrap(std::string name, bool guard) : ClapTrap() {
	this->_name = name;
	this->_hitPoints = SCAV_HP;
	this->_energy = SCAV_ENERGY;
	this->_damage = SCAV_DAMAGE;
	this->_guard = guard;
	std::cout << "ScavTrap constructor with args called" << std::endl;
};

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
	this->_guard = other._guard;
	std::cout << "ScavTrap copy constructor called" << std::endl;
};

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
};

ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
	if (this != &other) {
		_hitPoints = other._hitPoints;
		_energy = other._energy;
		_damage = other._damage;
		_guard = other._guard;
	}
	std::cout << "ScavTrap assignment operator called" << std::endl;
	return (*this);
};

void ScavTrap::attack(const std::string& target) {
	if (_energy > 0 && _hitPoints > 0) {
		std::cout << "ScavTrap " << this->_name << " attacked " << target << " and caused " << _damage << " of damage." << std::endl;
		_energy--;
	}
	else if (_energy == 0) {
		std::cout << "ScavTrap " << this->_name << " doesn't have enough energy to attack." << std::endl;
	}
	else {
		std::cout << "ScavTrap " << this->_name << " doesn't have enough hit points to attack." << std::endl;
	}
};

void ScavTrap::guardGate() {
	if (this->_energy > 0 && _guard == false) {
		std::cout << "ScavTrap " << this->_name << " entered GateKeeper mode." << std::endl;
		_energy--;
		_guard = true;
	}
	else if (this->_energy > 0) {
		std::cout << "ScavTrap " << this->_name << " exited GateKeeper mode." << std::endl;
		_energy--;
		_guard = false;
	}
	else {
		std::cout << "ScavTrap " << this->_name << " doesn't have energy to enter or exit GateKeeper mode." << std::endl;
	}
};