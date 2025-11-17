/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:04:30 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/24 19:28:05 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(const T &a, const T &b) {
	if (a < b)
		return a;
	return b;
}

template <typename T>
T	max(const T &a, const T &b) {
	if (a > b)
		return a;
	return b;
}
