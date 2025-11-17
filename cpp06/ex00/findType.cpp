/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:54:28 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/22 17:00:08 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool	intCheck(std::string const &input, size_t lenght) {
	bool	sign = false;
	size_t	i = 0;

	if (input[i] == '+' || input[i] == '-') {
		sign = true;
		i++;
	}
	if (lenght == 1 && sign)
		return false;
	while (i < lenght) {
		if (!isdigit(input[i]))
			break;
		i++;
	}
	if (i == lenght && ((sign && lenght < 11) || (!sign && lenght < 10)))
		return true;
	return false;
}

bool	floatCheck(std::string const &input, size_t lenght, size_t dot) {
	size_t	i = 0;

	if (input[i] == '+' || input[i] == '-')
		i++;

	while (i < dot) {
		if (!isdigit(input[i]))
			break;
		i++;
	}
	if (i != dot)
		return false;
	i++;
	while (i < lenght) {
		if (!isdigit(input[i]))
			break;
		i++;
	}
	if (input[i] == 'f' && !input[i + 1])
		return true;
	return false;
}

int	findType(std::string const &input, size_t lenght) {
	size_t	dot = input.find('.');
	size_t	f = input.find('f');
	bool	validInput;

	if (lenght == 0)
		return -1;
	if (dot != std::string::npos)
		validInput = validNumber(input.c_str());
	if (dot == std::string::npos) {
		if (input == "-inf" || input == "-inff" || input == "+inf" || input == "+inff" || input == "nan" || input == "nanf")
			return 0; //pseudo-literals
		else if (intCheck(input, lenght) == true)
			return 1; //int
		else if ((lenght == 1 && !isdigit(input[0])) || (lenght == 3 && input[0] == '\'' && input[3] == '\''))
			return 2; //char
	}
	else if (dot != std::string::npos && f == std::string::npos && validInput)
		return 3; //double
	else if (dot != std::string::npos && f != std::string::npos && validInput) {
		if (floatCheck(input, lenght, dot) == true)
			return 4; //float
	}
	return -1; //Invalid input
}

int precisionLenght(const char *input) {
	int	size = 0, i = 0;

	while (input[i] && input[i] != '.')
		i++;
	i++;
	while (input[i] && input[i] != 'f') {
		i++;
		size++;
	}
	if (size <= 0)
		return 1;
	else if (size > 5)
		return 5;
	else
		return size;
}

bool	validNumber(const char *input) {
	int i = 0;

	if (input[i] ==	'+' || input[i] == '-')
		i++;
	while (input[i]) {
		if (input[i] == '.')
			i++;
		else if (input[i] == 'f') {
			if (!input[i + 1])
				return true;
			else
				return false;
		}
		else if (isdigit(input[i]))
			i++;
		else
			return false;
	}
	return true;
}