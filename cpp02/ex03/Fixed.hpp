/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:56:05 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/14 18:23:34 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
		int					_fpNbr;
		static const int	_bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed(const int other);
		Fixed(const float other);
		~Fixed();
		Fixed	&operator=(const Fixed &other);
		bool	operator>(const Fixed &other) const;
		bool	operator<(const Fixed &other) const;
		bool	operator>=(const Fixed &other) const;
		bool	operator<=(const Fixed &other) const;
		bool	operator==(const Fixed &other) const;
		bool	operator!=(const Fixed &other) const;
		Fixed 	operator+(const Fixed &other) const;
		Fixed 	operator-(const Fixed &other) const;
		Fixed 	operator*(const Fixed &other) const;
		Fixed 	operator/(const Fixed &other) const;
		Fixed 	&operator++();
		Fixed 	&operator--();
		Fixed 	operator++(int);
		Fixed 	operator--(int);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed	&min(Fixed &nbrA, Fixed &nbrB);
		static Fixed	&max(Fixed &nbrA, Fixed &nbrB);
		static const Fixed	&min(const Fixed &nbrA, const Fixed &nbrB);
		static const Fixed	&max(const Fixed &nbrA, const Fixed &nbrB);
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif