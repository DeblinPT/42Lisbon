/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:16:15 by adimas-d          #+#    #+#             */
/*   Updated: 2023/06/20 23:20:20 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	int	numero;

	numero = 2147483647;
	printf("Prinf %020d\n", numero);
	ft_printf("ft_Printf %d\n", numero);
	return (numero);
}
