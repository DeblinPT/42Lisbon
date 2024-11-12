/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:10:27 by adimas-d          #+#    #+#             */
/*   Updated: 2024/04/30 19:28:30 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(t_table *table, size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
	{
		table->error = -6;
		return (NULL);
	}
	return (ret);
}

void	mutex_error_handler(int exit_code, t_code op_code)
{
	if (exit_code == 0)
		return ;
	else if (exit_code == EINVAL && (op_code == LOCK || op_code == UNLOCK
			|| op_code == DESTROY))
		error_print("The value specified by mutex is invalid.");
	else if (exit_code == EINVAL && op_code == INIT)
		error_print("The value specified by attr is invalid.");
	else if (exit_code == EDEADLK && op_code == LOCK)
		error_print("The current thread already owns the mutex.");
	else if (exit_code == EPERM && op_code == UNLOCK)
		error_print("The current thread does not own the mutex.");
	else if (exit_code == ENOMEM && op_code == INIT)
		error_print("Insufficient memory exists to initialize the mutex.");
	else if (exit_code == EBUSY && op_code == DESTROY)
		error_print("Detected an attempt to destroy the object referenced"
			" by mutex while it is locked or referenced");
	else if (exit_code == EPERM && op_code == INIT)
		error_print("The caller does not have the privilege to perform the"
			" operation.");
}

void	safe_mutex(t_mtx *mutex, t_code op_code)
{
	if (op_code == INIT)
		mutex_error_handler(pthread_mutex_init(mutex, NULL), op_code);
	else if (op_code == DESTROY)
		mutex_error_handler(pthread_mutex_destroy(mutex), op_code);
	else if (op_code == LOCK)
		mutex_error_handler(pthread_mutex_lock(mutex), op_code);
	else if (op_code == UNLOCK)
		mutex_error_handler(pthread_mutex_unlock(mutex), op_code);
	else
		error_print("Wrong op_code in mutex.");
}

void	pthread_error_hander(int exit_code, t_code op_code)
{
	if (exit_code == 0)
		return ;
	else if (exit_code == EINVAL && op_code == CREAT)
		error_print("Invalid settings in attr.");
	else if (exit_code == EINVAL && op_code == JOIN)
		error_print("thread is not a joinable thread OR Another"
			"thread is already waiting to join with this thread.");
	else if (exit_code == EINVAL && op_code == DETACH)
		error_print("thread is not a joinable thread.");
	else if (exit_code == ESRCH && op_code == JOIN)
		error_print("No thread with the ID thread could be found.");
	else if (exit_code == ESRCH && op_code == DETACH)
		error_print("No thread with the ID thread could be found.");
	else if (exit_code == EAGAIN)
		error_print("Insufficient resources to create another thread,or a"
			"system-imposed limit on the number of threads was encountered.");
	else if (exit_code == EPERM)
		error_print("No permission to set the scheduling policy and parameters"
			"specified in attr.");
	else if (exit_code == EDEADLOCK)
		error_print("A deadlock was detected");
	else
		error_print ("Wrong op_code in pthread.");
}

void	safe_pthread(pthread_t *thread, void *(*f)(void *), void *data,
		t_code op_code)
{
	if (op_code == CREAT)
		pthread_error_hander(pthread_create(thread, NULL, f, data), op_code);
	else if (op_code == JOIN)
		pthread_error_hander(pthread_join(*thread, NULL), op_code);
	else if (op_code == DETACH)
		pthread_error_hander(pthread_detach(*thread), op_code);
	else
		error_print("Wrong op_code in pthread.");
}
