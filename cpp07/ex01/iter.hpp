/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:15:33 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/28 18:57:32 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

template <typename T, typename F>

void	iter(T *array, size_t lenght, F func) {
	if (!array || !func)
		return ;
	for (size_t i = 0; i < lenght; i++)
		func(array[i]);
}