/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:06:00 by adimas-d          #+#    #+#             */
/*   Updated: 2023/06/15 21:37:08 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_length(char *base)
{
	int	ind;

	ind = 0;
	while (base[ind] != 0)
		ind++;
	return (ind);
}

int	ft_print_hex(int number, char *base)
{
	long	nb;
	int		res;

	nb = number;
	res = 1;
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb = -nb;
		res++;
	}
	if (nb / ft_length(base) != 0)
	{
		ft_print_hex(nb / (ft_length(base)), base);
		ft_putnbr_fd(base[nb % ft_length(base)], 1);
		res++;
	}
	else
	{
		ft_putnbr_fd(base[nb % ft_length(base)], 1);
		res++;
	}
	return (res);
}
