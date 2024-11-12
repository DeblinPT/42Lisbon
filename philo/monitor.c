/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:50:03 by adimas-d          #+#    #+#             */
/*   Updated: 2024/05/16 15:58:59 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	death(t_philo *philo)
{
	long	time_passed;
	long	time_to_die;

	safe_mutex(&philo->philo_mtx, LOCK);
	if (philo->full)
	{
		safe_mutex(&philo->philo_mtx, UNLOCK);
		return (false);
	}
	time_passed = (gettime() - philo->last_meal) / 1e3;
	time_to_die = philo->table->time_to_die / 1e3;
	safe_mutex(&philo->philo_mtx, UNLOCK);
	if (time_passed > time_to_die)
		return (true);
	else
		return (false);
}

void	*monitor_sim(void	*data)
{
	t_table	*table;
	int		i;

	table = (t_table *)data;
	while (!bool_get(&table->table_mtx, &table->sim_end))
	{
		i = 0;
		while (!bool_get(&table->table_mtx, &table->sim_end)
			&& i < table->philo_nbr)
		{
			if (death(&table->philos[i]))
			{
				safe_mutex(&table->table_mtx, LOCK);
				table->sim_end = true;
				safe_mutex(&table->table_mtx, UNLOCK);
				write_status(&table->philos[i], DIED);
			}
			i++;
		}
		usleep(50);
	}
	return (NULL);
}
