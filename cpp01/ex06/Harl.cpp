/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:02:55 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/05 18:11:40 by adimas-d         ###   ########.fr       */
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

int complaintLevel(std::string level) {
	if (!level.compare("DEBUG")) {
		return (1);
	}
	else if (!level.compare("INFO")) {
		return (2);
	}
	else if (!level.compare("WARNING")) {
		return (3);
	}
	else if (!level.compare("ERROR")) {
		return (4);
	}
	else {
		return (0);
	}
}

void harl::complain(std::string level) {
	int complaint = complaintLevel(level);
	switch (complaint)
	{
		case 0:
			std::cout << "Harl can't complain about that, ask a Karen!" << std::endl;
			break;
		case 1:
			debug();
		case 2:
			info();
		case 3:
			warning();
		case 4:
			error();
	}
	return ;
}