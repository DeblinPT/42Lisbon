/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:06:00 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/04 21:07:16 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn\'t put enough bacon in my burger! If you did, I wouldn\'t be asking for more!" << std::endl;
}

void harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I\'ve been coming for years whereas you started working here since last month." << std::endl;
}

void harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void harl::complain(std::string level) {
	std::string _coments[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (harl::*_commentsPtr[])(void) = {&harl::debug, &harl::info, &harl::warning, &harl::error};
	for (int i = 0; i < 4; i++) {
		if (level == _coments[i]) {
			(this->*_commentsPtr[i])();
			return ;
		}
	}
	std::cout << "Harl can't complain about that, ask a Karen!" << std::endl;
	return ;
}