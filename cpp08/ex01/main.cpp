/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:32:26 by adimas-d          #+#    #+#             */
/*   Updated: 2025/05/16 21:37:54 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try {
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	Span big(10001);
    std::vector<int> bulk(10001);
    for (int i = 0; i <= 10000; ++i)
		bulk[i] = i * 2;
	try {
    	big.addNumbers(bulk.begin(), bulk.end());
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
		std::cout << "Shortest span (bulk): " << big.shortestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	try {
    	std::cout << "Longest span (bulk): " << big.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}