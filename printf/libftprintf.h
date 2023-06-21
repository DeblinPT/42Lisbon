/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:34:38 by adimas-d          #+#    #+#             */
/*   Updated: 2023/06/21 20:09:01 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct t_flg
{
	int		i;
	bool	hashtag;
	int		zero;
	bool	minus;
	bool	space;
	bool	plus;
	int		width;
	int		percision;
}	t_flg;

int		ft_printf(const char *format, ...);
int		ft_print_char(char character);
int		ft_print_str(char *str);
int		ft_print_addr(int addr);
int		ft_print_nbr(int number);
int		ft_print_hex(int number, char *base);
int		ft_size(int numero);

void	ft_bonus(const char *flags, t_flg *flg1);

#endif