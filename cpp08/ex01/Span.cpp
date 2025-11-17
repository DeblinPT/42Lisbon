/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:32:46 by adimas-d          #+#    #+#             */
/*   Updated: 2025/05/16 21:51:29 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {
	std::cout << "Deafult constructor called" << std::endl;
}

Span::Span(unsigned int nbr) : _size(nbr) {
	std::cout << "ARG constructor called" << std::endl;
}

Span::Span(const Span &copy) : _data(copy._data), _size(copy._size) {
	std::cout << "Copy constructor called" << std::endl;
}

Span::~Span() {
	std::cout << "Destructor constructor called" << std::endl;
}

Span	&Span::operator=(const Span &other) {
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other) {
		_data = other._data;
		_size = other._size;
	}
	return *this;
}

void	Span::addNumber(int nbr) {
	if (_data.size() >= _size)
		throw MaxCap();
	_data.push_back(nbr);
}

int		Span::shortestSpan() const {
	if (_data.size() < 2)
		throw FewElements();

	std::vector<int> sorted = _data;
	std::sort(sorted.begin(), sorted.end());

	int newSpan = 0;
	int minSpan = sorted[1] - sorted[0];
	size_t size = sorted.size() - 1;
	for (size_t i = 1; i < size; i++) {
		newSpan = sorted[i + 1] - sorted[i];
		if (newSpan < minSpan)
			minSpan = newSpan;
	}
	return minSpan;
}

int		Span::longestSpan() const {
	if (_data.size() < 2)
		throw FewElements();
	
	int min = *std::min_element(_data.begin(), _data.end());
	int max = *std::max_element(_data.begin(), _data.end());
	return max - min;
}