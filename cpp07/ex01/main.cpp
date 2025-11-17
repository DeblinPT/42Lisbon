/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:10:22 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/28 20:12:16 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	ToLower(char &array) {
	array = std::tolower(static_cast<unsigned int>(array));
}

void	ToUpper(char &array) {
	array = std::toupper(static_cast<unsigned int>(array));
}

void	plusplus(int &array) {
	array = array + 1;
}

void	minusminus(int &array) {
	array = array - 1;
}

template<typename T>
void	change(T &thiss) {
	thiss = 65;
}

int	main(void) {
	char	charr[] = {'A', 'B', 'C'};
	char	*empty = NULL;
	int		intt[] = {0, 1, 2};

	std::cout << "Empty array:" << std::endl;
	::iter(empty, 0, toupper);
	std::cout << std::endl;

	std::cout << "Char array:" << std::endl;
	::iter(charr, 3, ToLower);
	std::cout << charr[0] << " = a" << std::endl;
	std::cout << charr[1] << " = b" << std::endl;
	std::cout << charr[2] << " = c" << std::endl;

	::iter(charr, 3, ToUpper);
	std::cout << charr[0] << " = A" << std::endl;
	std::cout << charr[1] << " = B" << std::endl;
	std::cout << charr[2] << " = C" << std::endl;

	::iter(charr, 3, change<char>);
	std::cout << charr[0] << " = " << (char)65 << std::endl;
	std::cout << charr[1] << " = " << (char)65 << std::endl;
	std::cout << charr[2] << " = " << (char)65 << std::endl;

	std::cout << "Int array:" << std::endl;
	::iter(intt, 3, plusplus);
	std::cout << intt[0] << " = 1" << std::endl;
	std::cout << intt[1] << " = 2" << std::endl;
	std::cout << intt[2] << " = 3" << std::endl;

	::iter(intt, 3, minusminus);
	std::cout << intt[0] << " = 0" << std::endl;
	std::cout << intt[1] << " = 1" << std::endl;
	std::cout << intt[2] << " = 2" << std::endl;

	::iter(intt, 3, change<int>);
	std::cout << intt[0] << " = 65" << std::endl;
	std::cout << intt[1] << " = 65" << std::endl;
	std::cout << intt[2] << " = 65" << std::endl;

	return 0;
}