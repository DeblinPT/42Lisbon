/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:21:01 by adimas-d          #+#    #+#             */
/*   Updated: 2023/06/21 20:12:01 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "ft_bonus.h"

void	ft_bonus(const char *format, t_flg *flg1)
{
	ft_flags_bonus(format, flg1);
	ft_width_bonus(format, flg1);
//	ft_precision_bonus(format, flg1);
}
