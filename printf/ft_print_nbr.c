/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:06:03 by adimas-d          #+#    #+#             */
/*   Updated: 2023/06/19 20:27:56 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_nbr(int number)
{
	int	res;

	res = ft_size(number);
	ft_putnbr_fd(number, 1);
	return (res);
}
