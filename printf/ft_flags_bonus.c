/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:52:26 by adimas-d          #+#    #+#             */
/*   Updated: 2023/06/21 20:11:00 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_bonus.h"

void	ft_pads(const char *flag, t_flg *flg1)
{
	int	pading;

	pading = 0;
	while (flag[flg1->i] > '0' && flag[flg1->i] < '9')
	{
		pading *= 10;
		pading += flag[flg1->i];
		flg1->i++;
	}
	flg1->zero = pading;
}

void	ft_flags_bonus(const char *flag, t_flg *flg1)
{
	while (flag[flg1->i] != '.' && flag[flg1->i] != '*' && flag[flg1->i] != 'c'
		&& flag[flg1->i] != 's' && flag[flg1->i] != 'p' && flag[flg1->i] != 'd'
		&& flag[flg1->i] != 'i' && flag[flg1->i] != 'u' && flag[flg1->i] != 'x'
		&& flag[flg1->i] != 'X' && flag[flg1->i] != '%')
	{
		if (flag[flg1->i] == '#')
			flg1->hashtag = 1;
		else if (flag[flg1->i] == '0')
			ft_pads(flag, flg1);
		else if (flag[flg1->i] == '-')
		{
			flg1->minus = 1;
			flg1->zero = 0;
		}
		else if (flag[flg1->i] == '+')
			flg1->plus = 1;
		else if (flag[flg1->i] == ' ')
		{
			flg1->space = 1;
			flg1->plus = 0;
		}
		flg1->i++;
	}
	return ;
}
