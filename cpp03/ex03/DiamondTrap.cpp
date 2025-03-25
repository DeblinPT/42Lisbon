/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:41:54 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/17 16:46:01 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name") {
	this->_name = "Default";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;
	std::cout << "DiamondTrap constructor called" << std::endl;
};

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energy = ScavTrap::_energy;
	this->_damage = FragTrap::_damage;
	std::cout << "DiamondTrap constructor with args called" << std::endl;
};

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	*this = other;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
};

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
};

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energy = other._energy;
		_damage = other._damage;
		ClapTrap::_name = other._name + "_clap_name";
	}
		std::cout << "DiamondTrap assignment operator called" << std::endl;

	return (*this);
};

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
};

void DiamondTrap::whoAmI() {
	std::cout << "My name is " << this->_name << " and my ancerters name is " << ClapTrap::_name << "." << std::endl;
};