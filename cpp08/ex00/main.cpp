/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:22:00 by adimas-d          #+#    #+#             */
/*   Updated: 2025/05/16 20:32:46 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int	main(void) {
	try {
		std::vector<int> vt;
		vt.push_back(10);
		vt.push_back(20);
		vt.push_back(30);

		std::vector<int>::iterator it = easyfind(vt, 20);
		std::cout << "Found: " << *it << std::endl;

		easyfind(vt, 40);
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}