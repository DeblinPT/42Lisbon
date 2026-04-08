/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:45:22 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/24 18:04:25 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool PhoneBook::isALetter(std::string input) {
	for (std::string::iterator i = input.begin(); i != input.end(); i++) {
		if (!std::isalpha(*i))
			return false;
	}
	return true;
}

bool PhoneBook::isNbr(std::string input) {
	for (std::string::iterator i = input.begin(); i != input.end(); i++) {
		if (!std::isdigit(*i))
			return false;
	}
	return true;
}

bool PhoneBook::isIndex(int input) {
	if (input > 0 && input < 9)
		return true;
	return false;
}

std::string PhoneBook::setValue(const std::string prompt, const int value) {
	std::string	input;
	bool		isValid;

	do {
		std::cout << prompt;
		std::getline(std::cin, input);
		isValid = !input.empty();
		if (value < 2)
			isValid &= isALetter(input);
		else if (value == 3)
			isValid &= isNbr(input);
		if (!isValid) {
			std::cout << "Invalid input." << std::endl;
		}
	}
	while(!isValid && !std::cin.eof());
	return input;
}

void PhoneBook::addContact() {
	std::string first;
	std::string last;
	std::string nick;
	std::string nbr;
	std::string secret;

	first = setValue("First Name: ", 0);
	last = setValue("Last Name: ", 1);
	nick = setValue("Nick Name: ", 2);
	nbr = setValue("Phone Number: ", 3);
	secret = setValue("Darkest Secret: ", 4);

	contacts[curIndex].createContact(first, last, nick, nbr, secret);
	curIndex++;
	if (curIndex >= 8)
		curIndex = 0;
	if (count < 8)
		count++;
}

std::string PhoneBook::adjOutput(std::string output) {
	if (output.length() > 10) {
		output.erase(output.begin() + 9, output.end());
		output.append(".");
	}
	return output;
}

void PhoneBook::search() {
	std::string input;
	int index;

	if (count == 0) {
		std::cout << "The PhoneBook is empty." << std::endl;
		return;
	}
	
	std::cout << "|   INDEX  |FIRST NAME|LAST NAME | NICKNAME |" << std::endl;
	for (int i = 0; i < count; i++){
		std::cout << "|" << std::setfill(' ') << std::setw(10) << i + 1
		<< "|" << std::setw(10) << adjOutput(contacts[i].getFirstName())
		<< "|" << std::setw(10) << adjOutput(contacts[i].getLastName())
		<< "|" << std::setw(10) << adjOutput(contacts[i].getNickName())
		<< "|" << std::endl;
	}
	
	do {
		std::cout << "Choose an index or press enter to go back: ";
		std::getline(std::cin, input);
		if (isNbr(input) && !input.empty()) {
			std::istringstream iss(input);
			if (!(iss >> index) || !isIndex(index) || index > count)
				std::cout << "Please inser a valid index." << std::endl;
			else {
				std::cout << "First Name: " << contacts[index - 1].getFirstName() << std::endl;
				std::cout << "Last Name: " << contacts[index - 1].getLastName() << std::endl;
				std::cout << "Nick Name: " << contacts[index - 1].getNickName() << std::endl;
				std::cout << "Phone Number: " << contacts[index - 1].getPhoneNumber() << std::endl;
				std::cout << "Darkest Secret: " << contacts[index - 1].getDarkestSecret() << std::endl;
			}
		}
		else if (input.empty()) {
			std::cout << "Exiting..." << std::endl;
			return ;
		}
		else
			std::cout << "Please inser a valid index." << std::endl;
		
	}
	while (!input.empty() && !std::cin.eof());
	return ;
}

int main() {
	std::string command;
	PhoneBook book;
	while (std::cin.good()) {
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			book.addContact();
		else if (command == "SEARCH")
			book.search();
		else
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}