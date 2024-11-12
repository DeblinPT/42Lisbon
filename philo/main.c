/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:25:14 by adimas-d          #+#    #+#             */
/*   Updated: 2024/05/09 19:56:29 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;
	int		error;

	table.error = 0;
	if (ac >= 5 && ac <= 6)
	{
		parse_input(&table, av);
		error = table.error;
		if (table.error == 0)
		{
			get_ready(&table);
			if (table.error == 0)
				start_sim(&table);
			error = table.error;
			clear(&table);
		}
	}
	else
	{
		table.error = -7;
		error = table.error;
		error_list(table.error);
	}
	return (error);
}
