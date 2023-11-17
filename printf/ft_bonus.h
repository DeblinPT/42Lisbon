/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:39:40 by adimas-d          #+#    #+#             */
/*   Updated: 2023/08/16 18:56:58 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BONUS_H
# define FT_BONUS_H

# include "ft_printf.h"

void	ft_flags1_bonus(const char **format, t_flg *flg1);
void	ft_width_bonus(const char **format, t_flg *flg1);
void	ft_precision_bonus(const char **format, t_flg *flg1);
int		ft_precision_print(char *str, t_flg *flg1);
int		ft_add_nbr_width(unsigned int number, t_flg *flg1);
int		ft_add_uns_width(unsigned int number, t_flg *flg1);
int		ft_uns_nbr_size(unsigned int number);
int		ft_size_of_nbr(unsigned int number);
void	ft_precision_size(const char **format, t_flg *flg1);
int		ft_nbr_precision(int number, t_flg *flg1);
int		ft_add_precision(int number, t_flg *flg1);

#endif