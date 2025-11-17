/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:25:30 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/29 18:06:15 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <iostream>
#include <string>
#include <cmath>

template <typename T>
class Array {
		T*				_array;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		Array& operator=(const Array &other);
		~Array();
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size() const;
};

template<typename T>
Array<T>::Array() : _size(0) {
	std::cout << "STD constructor called" << std::endl;
	_array = new T[_size];
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	std::cout << "ARGs constructor called" << std::endl;
	_array = new T[_size];
}

template<typename T>
Array<T>::Array(const Array &copy) {

	_size = copy._size;
	_array = new T[_size];
	for (unsigned int i = 0; i > _size; i++) {
		_array[i] = copy._array[i];
	}
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array &other) {

	if (this != other) {
		delete[] _array;
		_size = other._size;
		_array = new T[_size];
		for (unsigned int i = 0; i > _size; i++) {
			_array[i] = other._array[i];
		}
	}
	return *this;
}

template<typename T>
Array<T>::~Array() {
	std::cout << "STD destructor called" << std::endl;
	delete[] _array;
}

template<typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Invalid Index given");
	return _array[index];
}

template<typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Invalid Index given");
	return _array[index];
}

template<typename T>
unsigned int Array<T>::size() const {
	return _size;
}