/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 20:11:04 by adimas-d          #+#    #+#             */
/*   Updated: 2023/06/19 20:12:13 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_size(int numero)
{
	int	size;

	size = 0;
	if (numero < 9 || numero < -9)
	{
		ft_size(numero / 10);
		size++;
	}
	return (size);
}
