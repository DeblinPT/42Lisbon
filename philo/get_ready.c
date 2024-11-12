/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ready.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:40:14 by adimas-d          #+#    #+#             */
/*   Updated: 2024/05/09 19:14:28 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	assign_forks(t_table *table, int philo_pos)
{
	int	phi_nbr;

	phi_nbr = table->philo_nbr;
	if (philo_pos % 2 != 0)
	{
		table->philos[philo_pos].fork_one = &table->forks[philo_pos];
		table->philos[philo_pos].fork_two
			= &table->forks[(philo_pos + 1) % phi_nbr];
	}
	else
	{
		table->philos[philo_pos].fork_one
			= &table->forks[(philo_pos + 1) % phi_nbr];
		table->philos[philo_pos].fork_two = &table->forks[philo_pos];
	}
}

void	init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_counter = 0;
		table->philos[i].full = false;
		table->philos[i].table = table;
		safe_mutex(&table->philos[i].philo_mtx, INIT);
		assign_forks(table, i);
		i++;
	}
}

long	get_ready(t_table *table)
{
	int	i;

	i = 0;
	table->sim_end = false;
	table->philos = safe_malloc(table, sizeof(t_philo) * table->philo_nbr);
	table->forks = safe_malloc(table, sizeof(t_fork) * table->philo_nbr);
	table->threads_runnig = 0;
	table->full_philos = 0;
	table->time_to_think = ((table->time_to_eat * 2) - table->time_to_sleep);
	if (table->philos == NULL || table->forks == NULL)
		return (-6);
	if (table->error == 0)
	{
		safe_mutex(&table->write_mtx, INIT);
		safe_mutex(&table->table_mtx, INIT);
		table->lets_start = false;
		while (i < table->philo_nbr)
		{
			table->forks[i].fork_id = i;
			safe_mutex(&table->forks[i].mtx_fork, INIT);
			i++;
		}
		init_philo(table);
	}
	return (0);
}
