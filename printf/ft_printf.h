/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:34:38 by adimas-d          #+#    #+#             */
/*   Updated: 2023/08/16 18:54:39 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct t_flg
{
	bool	hashtag;
	int		zero;
	bool	minus;
	bool	space;
	int		printlimit;
	bool	plus;
	int		width;
	bool	point;
	int		precision;
	bool	printminus;
}	t_flg;

int		ft_printf(const char *format, ...);
int		ft_print_char(char character, t_flg *flg1);
int		ft_str_error_check(char *str, t_flg *flg1);
int		ft_print_addr(unsigned long long addr, t_flg *flg1);
int		ft_print_nbr(int number, t_flg *flg1);
int		ft_print_uns_nbr(unsigned int num, char *base, t_flg *flg1);
int		ft_print_base(unsigned int number, char *base, t_flg *flg1, char *hash);
int		ft_size(int numero);
void	ft_bonus(const char **flags, t_flg *flg1);
int		ft_nbr_size(int number);

#endif