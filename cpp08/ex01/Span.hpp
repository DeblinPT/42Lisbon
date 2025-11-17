/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:32:38 by adimas-d          #+#    #+#             */
/*   Updated: 2025/05/07 17:49:29 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>

class MaxCap : public std::exception {
	public:
		const char *what() const throw() {
			return "Exceeds maximum capacity.";
		}
};

class FewElements : public std::exception {
	public:
		const char *what() const throw() {
			return "Not enough elements.";
		}
};

class Span {
		std::vector<int>	_data;
		unsigned int 		_size;
		Span();

	public:
		Span(unsigned int);
		Span(const Span &);
		Span	&operator=(const Span &);
		~Span();
		void	addNumber(int);
		int		shortestSpan() const;
		int		longestSpan() const;
		template<typename it>
		void	addNumbers(it, it);
};

#include "Span.tpp"