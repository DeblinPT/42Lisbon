/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:59:34 by adimas-d          #+#    #+#             */
/*   Updated: 2024/05/16 15:56:53 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <stdbool.h>
# include <limits.h>
# include <errno.h>
# include <sys/time.h>

# define RST	"\033[0m"
# define RED	"\033[1;31m"
//# define malloc() 0

typedef enum e_code
{
	INIT,
	DESTROY,
	LOCK,
	UNLOCK,
	CREAT,
	JOIN,
	DETACH
}				t_code;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FORK_ONE,
	TAKE_FORK_TWO,
	DIED
}				t_status;

typedef pthread_mutex_t	t_mtx;

typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mtx	mtx_fork;
	long	fork_id;
}				t_fork;

typedef struct s_philo
{
	int			id;
	long		meals_counter;
	long		last_meal;
	bool		full;
	t_fork		*fork_one;
	t_fork		*fork_two;
	pthread_t	thread_id;
	t_table		*table;
	t_mtx		philo_mtx;
}				t_philo;

typedef struct s_table
{
	long		philo_nbr;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		time_to_think;
	long		max_nbr_meals;
	long		sim_strart;
	bool		sim_end;
	bool		lets_start;
	long		threads_runnig;
	long		full_philos;
	long		error;
	t_mtx		table_mtx;
	t_mtx		write_mtx;
	pthread_t	monitor;
	t_philo		*philos;
	t_fork		*forks;
}				t_table;

/*utils*/
void	error_print(char *error);
void	error_list(long error_code);
long	gettime(void);
void	thread_start(t_table *table);
void	write_status(t_philo *philo, t_status status);

/*utils2*/
void	clear(t_table *table);
bool	is_even(long nbr);
void	is_finnished(t_table *table);
void	increase_thread_count(t_table *table);

/*parsing*/
void	parse_input(t_table *table, char **av);

/*safe_functions*/
void	*safe_malloc(t_table *table, size_t bytes);
void	safe_mutex(t_mtx *mutex, t_code op_code);

void	safe_pthread(pthread_t *thread, void *(*f)(void *), void *data,
			t_code op_code);

/*get_ready*/
long	get_ready(t_table *table);

/*start_sim*/
void	start_sim(t_table *table);
void	*meal_sim(void *data);

/*motinor*/
void	*monitor_sim(void	*data);

/*get_set*/
long	long_get(t_mtx *mutex, long *data);
bool	bool_get(t_mtx *mutex, bool *data);

#endif
