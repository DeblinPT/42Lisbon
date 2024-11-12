/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:01:39 by adimas-d          #+#    #+#             */
/*   Updated: 2024/05/16 15:36:27 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

int	num_len(char *str)
{
	int	len;

	len = 0;
	while (str)
	{
		if (is_digit(*str))
			len++;
		else
			return (-4);
		str++;
	}
	return (len);
}

char	*valid_input(t_table *table, char *str)
{
	char	*num;

	num = NULL;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		table->error = -3;
		return (num);
	}
	num = str;
	while (*str)
	{
		if (!is_digit(*str++))
		{
			table->error = -4;
			return (num);
		}
	}
	str = num;
	if (num_len(str) > 10)
		table->error = -5;
	return (num);
}

long	my_atol(t_table *table, char *str)
{
	long	num;

	num = 0;
	str = valid_input(table, str);
	while (table->error == 0 && is_digit(*str))
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	if (num > INT_MAX)
		table->error = -2;
	return (num);
}

//	usleep takes microseconds(0,001ms), the user is passing miliseconds
//	1e3 = 1 000
//	1e4 = 10 000
//	1e5 = 100 000
//	1e6 = 1 000 000

void	parse_input(t_table *table, char **av)
{
	table->philo_nbr = my_atol(table, av[1]);
	table->time_to_die = my_atol(table, av[2]) * 1e3;
	table->time_to_eat = my_atol(table, av[3]) * 1e3;
	table->time_to_sleep = my_atol(table, av[4]) * 1e3;
	if (av[5])
		table->max_nbr_meals = my_atol(table, av[5]);
	else
		table->max_nbr_meals = -1;
	if (table->error < 0)
		error_list(table->error);
}
