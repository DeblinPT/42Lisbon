/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:53:29 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/03 19:56:58 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string replaceWithStr(std::string original, std::string lookFor, std::string replaceWith) {
	for (int pos = original.find(lookFor); pos != -1; pos = original.find(lookFor)) {
		original.erase(pos, lookFor.length());
		original.insert(pos, replaceWith);
	}
	return (original);
}

bool emptyStr(std::string s1, std::string s2) {
	if (s1.empty() || s2.empty())
		return true;
	return false;
}

void replace(char **av) {
	if (emptyStr(av[2], av[3])) {
		std::cout << "None of the strings can be empty." << std::endl;
		return;
	}
	std::string fileType(".replace");
	std::string newName(av[1] + fileType);
	std::fstream in(av[1], std::ios::in);
	if (in.is_open()) {}
	else {
		std::cout << "Unable to open in file." << std::endl;
		return;
	}
	std::fstream out(newName.c_str(), std::ios::out);
	std::string outStr;
	if (out.is_open()) {}
	else {
		std::cout << "Unable to open in file." << std::endl;
		in.close();
		return;
	}
	while (getline(in, outStr)) {
		outStr = replaceWithStr(outStr, av[2], av[3]);
		out << outStr << std::endl;
	}
	in.close();
	out.close();
}