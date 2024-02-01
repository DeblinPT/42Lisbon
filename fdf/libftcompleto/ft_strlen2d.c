/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:43:43 by adimas-d          #+#    #+#             */
/*   Updated: 2024/01/12 18:44:59 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen2d(const char **str)
{
	size_t	index;

	index = 0;
	while (str[index] != 0)
		index++;
	return (index);
}
