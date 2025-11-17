/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:28:15 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/22 16:43:23 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	printPseuso(std::string const &input) {
	if (input == "nan" || input == "nanf") {
		std::cout << "Int		-> Impossible" << std::endl;
		std::cout << "Char		-> Impossible" << std::endl;
		std::cout << "Double		-> nan" << std::endl;
		std::cout << "Float		-> naf" << std::endl;
	}
	else if (input == "-inf" || input == "-inff") {
		std::cout << "Int		-> Impossible" << std::endl;
		std::cout << "Char		-> Impossible" << std::endl;
		std::cout << "Double		-> -inf" << std::endl;
		std::cout << "Float		-> -inff" << std::endl;
	}
	else if (input == "+inf" || input == "+inff") {
		std::cout << "Int		-> Impossible" << std::endl;
		std::cout << "Char		-> Impossible" << std::endl;
		std::cout << "Double		-> +inf" << std::endl;
		std::cout << "Float		-> +inff" << std::endl;
	}
}

void	printInt(std::string const &input) {
	long	nbr = atol(input.c_str());
	if ((input.length() > 11 && nbr < std::numeric_limits<int>::min()) || (input.length() > 10 && nbr > std::numeric_limits<int>::max()))
		std::cout << "Int		-> Impossible" << std::endl;
	else
		std::cout << "Int		-> " << static_cast<int>(nbr) << std::endl;
	if (nbr < 0 || nbr > 127)
		std::cout << "Char		-> Impossible" << std::endl;
	else if (isprint(nbr))
		std::cout << "Char		-> " << "'" << static_cast<char>(nbr) << "'" << std::endl;
	else
		std::cout << "Char		-> Undisplayable" << std::endl;
	std::cout << "Double		-> " << std::fixed << std::setprecision(1) << static_cast<double>(nbr) << std::endl;
	std::cout << "Float		-> " << std::fixed << std::setprecision(1) << static_cast<float>(nbr) << "f" << std::endl;
}

void	printChar(std::string const &input) {
	char	c;
	if (!input[1])
	c = input[0];
	else
	c = input[1];
	std::cout << "Int		-> " << static_cast<int>(c) << std::endl;
	std::cout << "Char		-> ";
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Undisplayable" << std::endl;
	std::cout << "Double		-> " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
	std::cout << "Float		-> " << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
}

void	printDouble(std::string const &input) {
	double	nbr = atof(input.c_str());
	int		presisionSize = precisionLenght(input.c_str());

	std::cout << "Int		-> ";
	if ((input.length() > 11 && nbr < std::numeric_limits<int>::min()) || (input.length() > 10 && nbr > std::numeric_limits<int>::max()))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(nbr) << std::endl;
	
	std::cout << "Char		-> ";
	if (nbr < 0 || nbr > 127)
		std::cout << "Impossible" << std::endl;
	else if (!isprint(nbr))
		std::cout << "Undisplayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(nbr) << "'" << std::endl;

	std::cout << "Double		-> ";
//	if ((nbr < std::numeric_limits<double>::min() && nbr > -std::numeric_limits<double>::min()) || nbr > std::numeric_limits<double>::max())
//		std::cout << "Impossible" << std::endl;
//	else
		std::cout << std::fixed << std::setprecision(presisionSize) << nbr << std::endl;
	
	std::cout << "Float		-> ";
//	if (double(nbr < std::numeric_limits<float>::min() && nbr > -std::numeric_limits<float>::min()) || nbr > std::numeric_limits<float>::max())
//		std::cout << "Impossible" << std::endl;
//	else
		std::cout << std::setprecision(presisionSize) << static_cast<float>(nbr) << "f" << std::endl;
}

void	printFloat(std::string const &input) {
	float	nbr = atof(input.c_str());
	int		presisionSize = precisionLenght(input.c_str());

	std::cout << "Int		-> ";
	if ((input.length() > 11 && nbr < std::numeric_limits<int>::min()) || (input.length() > 10 && nbr > std::numeric_limits<int>::max()))
		std::cout << "Impossible" << std::endl;
	else
		std::cout << static_cast<int>(nbr) << std::endl;

	std::cout << "Char		-> ";
	if (nbr >= 0 && nbr <= 127) {
		if (isprint(nbr))
			std::cout << nbr << std::endl;
		else
			std::cout << "Undisplayable" << std::endl;
	}
	else
		std::cout << "Impossible" << std::endl;

	std::cout << "Double		-> ";
//	if ((nbr < std::numeric_limits<double>::min() && nbr > -std::numeric_limits<double>::min()) || nbr > std::numeric_limits<double>::max())
//		std::cout << "Impossible" << std::endl;
//	else
		std::cout << std::fixed << std::setprecision(presisionSize) << static_cast<double>(nbr) << std::endl;

	std::cout << "Float		-> ";
//	if (double(nbr < std::numeric_limits<float>::min() && nbr > -std::numeric_limits<float>::min()) || nbr > std::numeric_limits<float>::max())
//		std::cout << "Impossible" << std::endl;
//	else
		std::cout << std::setprecision(presisionSize) << nbr << "f" << std::endl;
}