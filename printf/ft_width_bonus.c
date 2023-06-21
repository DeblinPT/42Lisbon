/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:53:54 by adimas-d          #+#    #+#             */
/*   Updated: 2023/06/21 20:09:24 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_bonus.h"

void	ft_width_bonus(const char *flag, t_flg *flg1)
{
	while (flag[flg1->i] >= '0' && flag[flg1->i] <= '9')
	{
		flg1->width = (flg1->width * 10) + (flag[flg1->i] - '0');
		flg1->i++;
	}
	return ;
}
