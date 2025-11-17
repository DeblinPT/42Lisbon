/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:04:02 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/22 16:23:47 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter
{
		ScalarConverter();
		ScalarConverter(ScalarConverter const&);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &other);
	public:
		static void convert(const std::string &input);
};

int		findType(std::string const &input, size_t lenght);
bool	validNumber(const char *input);
int		precisionLenght(const char *input);
void	printPseuso(std::string const &input);
void	printInt(std::string const &input);
void	printChar(std::string const &input);
void	printDouble(std::string const &input);
void	printFloat(std::string const &input);