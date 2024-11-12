/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:31:41 by adimas-d          #+#    #+#             */
/*   Updated: 2024/05/16 16:00:08 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*alone(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	safe_mutex(&philo->philo_mtx, LOCK);
	philo->last_meal = gettime();
	safe_mutex(&philo->philo_mtx, UNLOCK);
	safe_mutex(&philo->fork_one->mtx_fork, LOCK);
	write_status(philo, TAKE_FORK_ONE);
	while (!bool_get(&philo->table->table_mtx, &philo->table->sim_end))
		usleep(100);
	safe_mutex(&philo->fork_two->mtx_fork, UNLOCK);
	return (NULL);
}

void	thinking(t_philo *philo)
{
	long	t_to_think;

	write_status(philo, THINKING);
	if (is_even(philo->table->philo_nbr) == true)
		return ;
	t_to_think = philo->table->time_to_think;
	if (t_to_think < 0)
		t_to_think = 0;
	usleep(t_to_think * 0.2);
}

void	eat(t_philo *philo)
{
	safe_mutex(&philo->fork_one->mtx_fork, LOCK);
	write_status(philo, TAKE_FORK_ONE);
	safe_mutex(&philo->fork_two->mtx_fork, LOCK);
	write_status(philo, TAKE_FORK_TWO);
	safe_mutex(&philo->philo_mtx, LOCK);
	philo->last_meal = gettime();
	philo->meals_counter++;
	safe_mutex(&philo->philo_mtx, UNLOCK);
	write_status(philo, EATING);
	usleep(philo->table->time_to_eat);
	if (long_get(&philo->table->table_mtx, &philo->table->max_nbr_meals) > 0
		&& philo->table->max_nbr_meals == philo->meals_counter)
	{
		safe_mutex(&philo->philo_mtx, LOCK);
		philo->full = true;
		safe_mutex(&philo->philo_mtx, UNLOCK);
		safe_mutex(&philo->table->table_mtx, LOCK);
		philo->table->full_philos = philo->table->full_philos + 1;
		safe_mutex(&philo->table->table_mtx, UNLOCK);
	}
	safe_mutex(&philo->fork_one->mtx_fork, UNLOCK);
	safe_mutex(&philo->fork_two->mtx_fork, UNLOCK);
}

void	*meal_sim(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	safe_mutex(&philo->philo_mtx, LOCK);
	philo->last_meal = gettime();
	safe_mutex(&philo->philo_mtx, UNLOCK);
	while (!bool_get(&philo->table->table_mtx, &philo->table->sim_end))
	{
		if (bool_get(&philo->philo_mtx, &philo->full))
			break ;
		eat(philo);
		write_status(philo, SLEEPING);
		usleep(philo->table->time_to_sleep);
		thinking(philo);
	}
	return (NULL);
}

void	start_sim(t_table *table)
{
	int	i;

	i = 0;
	safe_mutex(&table->table_mtx, LOCK);
	table->sim_strart = gettime();
	safe_mutex(&table->table_mtx, UNLOCK);
	if (table->max_nbr_meals == 0)
		return ;
	else if (table->philo_nbr == 1)
		safe_pthread(&table->philos[0].thread_id, alone, &table->philos[0],
			CREAT);
	else
		thread_start(table);
	usleep(table->time_to_eat * 0.1);
	safe_pthread(&table->monitor, monitor_sim, table, CREAT);
	while (i < table->philo_nbr)
	{
		safe_pthread(&table->philos[i].thread_id, NULL, NULL, JOIN);
		i++;
	}
	is_finnished(table);
	safe_pthread(&table->monitor, NULL, NULL, JOIN);
}
