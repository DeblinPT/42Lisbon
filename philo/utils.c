/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:50:31 by adimas-d          #+#    #+#             */
/*   Updated: 2024/05/14 21:10:03 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_print(char *error)
{
	printf(RED"%s\n"RST, error);
}

void	error_list(long error_code)
{
	if (error_code == 0)
		return ;
	else if (error_code == -1)
		error_print("Please insert the correct number of arguments.");
	else if (error_code == -2)
		error_print("Argument passed is bigger them INT_MAX");
	else if (error_code == -3)
		error_print("Negative arguments not allowed.");
	else if (error_code == -4)
		error_print("Please input valid numbers.");
	else if (error_code == -5)
		error_print("Argument passed is bigger them INT_MAX");
	else if (error_code == -6)
		error_print("Error on memory allocation.");
	else if (error_code == -7)
		error_print("Please insert the correct number of arguments.");
}

long	gettime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		error_print("Get Time Of Day failed");
	return ((time.tv_sec * 1e6) + time.tv_usec);
}

void	thread_start(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		safe_pthread(&table->philos[i].thread_id, meal_sim,
			&table->philos[i], CREAT);
		i++;
	}
}

void	write_status(t_philo *philo, t_status status)
{
	long	time;

	safe_mutex(&philo->table->write_mtx, LOCK);
	safe_mutex(&philo->table->table_mtx, LOCK);
	time = (gettime() - philo->table->sim_strart) / 1e3;
	if ((status == TAKE_FORK_ONE || status == TAKE_FORK_TWO)
		&& !philo->table->sim_end)
		printf("%-6ld %d  has taken a fork\n", time, philo->id);
	else if (status == EATING && !philo->table->sim_end)
		printf("%-6ld %d  is eating\n", time, philo->id);
	else if (status == SLEEPING && !philo->table->sim_end)
		printf("%-6ld %d  is sleeping\n", time, philo->id);
	else if (status == THINKING && !philo->table->sim_end)
		printf("%-6ld %d  is thinking\n", time, philo->id);
	else if (status == DIED)
		printf("%-6ld %d  died\n", time, philo->id);
	safe_mutex(&philo->table->write_mtx, UNLOCK);
	safe_mutex(&philo->table->table_mtx, UNLOCK);
}
