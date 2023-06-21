/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 23:35:04 by adimas-d          #+#    #+#             */
/*   Updated: 2023/06/21 20:06:00 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
Can use malloc, free, write, va_start, va_arg, va_copy, va_end

Verify Flags
"-", "+", " ", "#", "0"

Verify Specifier
c, s, p, d, i, u, x, X, %
*/

int	ft_specifier(va_list args, char specifier)
{
	int	printed;

	printed = 0;
	if (specifier == 'c')
		printed += ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		printed += ft_print_str(va_arg(args, char *));
	else if (specifier == 'p')
		printed += ft_print_addr(va_arg(args, size_t));
	else if (specifier == 'd' || specifier == 'i')
		printed += ft_print_nbr(va_arg(args, int));
	else if (specifier == 'u')
		printed += ft_print_nbr(va_arg(args, int));
	else if (specifier == 'x')
		printed += ft_print_hex(va_arg(args, int), "0123456789abcdef");
	else if (specifier == 'X')
		printed += ft_print_hex(va_arg(args, int), "0123456789ABCDEF");
	else if (specifier == '%')
		printed += ft_print_char('%');
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		printed;
	t_flg	flg1;

	ft_memset(&flg1, 0, sizeof(flg1));
	va_start(list, format);
	printed = 0;
	flg1.i = 0;
	while (format[flg1.i])
	{
		if (format[flg1.i] == '%')
		{
			flg1.i++;
			ft_bonus(format, &flg1);
			printed += ft_specifier(list, format[flg1.i]);
		}
		else
		{
			ft_putchar_fd(format[flg1.i], 1);
			printed++;
		}
		flg1.i++;
	}
	va_end(list);
	return (printed);
}
