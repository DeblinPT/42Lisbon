/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:57:04 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/17 14:33:27 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->_hitPoints = FRAG_HP;
	this->_energy = FRAG_ENERGY;
	this->_damage = FRAG_DAMAGE;
	std::cout << "FragTrap constructor called" << std::endl;
};

FragTrap::FragTrap(std::string name) : ClapTrap() {
	this->_name = name;
	this->_hitPoints = FRAG_HP;
	this->_energy = FRAG_ENERGY;
	this->_damage = FRAG_DAMAGE;
	std::cout << "FragTrap constructor with args called" << std::endl;
};

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called" << std::endl;
};

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
};

FragTrap &FragTrap::operator=(FragTrap const &other) {
	if (this != &other) {
		_hitPoints = other._hitPoints;
		_energy = other._energy;
		_damage = other._damage;
	}
	std::cout << "FragTrap assignment operator called" << std::endl;
	return (*this);
};

void FragTrap::highFivesGuys(void) {

	std::cout << "FragTrap " << this->_name << " gave a high five to everyone!" << std::endl;
}