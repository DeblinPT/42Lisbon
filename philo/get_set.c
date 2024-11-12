/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:35:18 by adimas-d          #+#    #+#             */
/*   Updated: 2024/05/15 17:33:25 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	long_get(t_mtx *mutex, long *data)
{
	long	res;

	safe_mutex(mutex, LOCK);
	res = *data;
	safe_mutex(mutex, UNLOCK);
	return (res);
}

bool	bool_get(t_mtx *mutex, bool *data)
{
	bool	res;

	safe_mutex(mutex, LOCK);
	res = *data;
	safe_mutex(mutex, UNLOCK);
	return (res);
}
