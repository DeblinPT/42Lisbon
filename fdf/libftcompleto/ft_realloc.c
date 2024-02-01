/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:12:42 by adimas-d          #+#    #+#             */
/*   Updated: 2024/01/31 19:52:52 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (new_size == 0)
	{
		free(old_ptr);
		return (NULL);
	}
	else if (!old_ptr)
		return (malloc(new_size));
	else if (new_size <= old_size)
		return (old_ptr);
	else
	{
		new_ptr = malloc(new_size);
		if (new_ptr)
		{
			ft_memcpy(new_ptr, old_ptr, old_size);
			free(old_ptr);
		}
		return (new_ptr);
	}
}
