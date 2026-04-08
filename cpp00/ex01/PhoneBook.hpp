/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:44:06 by adimas-d          #+#    #+#             */
/*   Updated: 2025/01/24 17:30:41 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <sstream>

class PhoneBook
{
	Contact		contacts[8];
	int 		count;
	int			curIndex;
	std::string	setValue(const std::string prompt, const int value);
	bool		isALetter(std::string input);
	bool		isNbr(std::string input);
	bool 		isIndex(int input);
	std::string adjOutput(std::string output);

	public:
		PhoneBook() : count(0), curIndex(0) {};
		void	addContact();
		void	search();
		
};

#endif