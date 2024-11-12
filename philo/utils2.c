/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:36:30 by adimas-d          #+#    #+#             */
/*   Updated: 2024/05/16 15:58:23 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clear(t_table *table)
{
	t_philo	philo;
	int		i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (table->philos != NULL)
		{
			philo = table->philos[i];
			safe_mutex(&philo.philo_mtx, DESTROY);
		}
		i++;
	}
	safe_mutex(&table->table_mtx, DESTROY);
	safe_mutex(&table->write_mtx, DESTROY);
	if (table->philos != NULL)
		free(table->philos);
	if (table->forks != NULL)
		free(table->forks);
}

bool	is_even(long nbr)
{
	if (nbr % 2 == 0)
		return (true);
	return (false);
}

void	is_finnished(t_table *table)
{
	while (!bool_get(&table->table_mtx, &table->sim_end))
	{
		if (long_get(&table->table_mtx, &table->full_philos)
			== table->philo_nbr)
		{
			safe_mutex(&table->table_mtx, LOCK);
			table->sim_end = true;
			safe_mutex(&table->table_mtx, UNLOCK);
		}
		usleep(50);
	}
}

void	increase_thread_count(t_table *table)
{
	safe_mutex(&table->table_mtx, LOCK);
	table->threads_runnig++;
	safe_mutex(&table->table_mtx, UNLOCK);
}
