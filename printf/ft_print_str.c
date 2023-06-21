/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:06:06 by adimas-d          #+#    #+#             */
/*   Updated: 2023/06/15 20:55:01 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_str(char *str)
{
	int	res;

	res = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (res);
}
