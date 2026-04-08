/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 19:17:59 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/24 18:17:33 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//Contact::~Contact() {}

Contact::Contact() {
	_first_name = std::string();
	_last_name = std::string();
	_nick_name = std::string();
	_phone_number = std::string();
	_darkest_secret = std::string();
}

void Contact::createContact(const std::string first, const std::string last, 
							const std::string nick, const std::string nbr,
							const std::string secret) {
	_first_name = first;
	_last_name = last;
	_nick_name = nick;
	_phone_number = nbr;
	_darkest_secret = secret;
}

std::string Contact::getFirstName() {
	return _first_name;
}

std::string Contact::getLastName() {
	return _last_name;
}

std::string Contact::getNickName() {
	return _nick_name;
}

std::string Contact::getPhoneNumber() {
	return _phone_number;
}

std::string Contact::getDarkestSecret() {
	return _darkest_secret;
}