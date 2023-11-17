/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:47:18 by adimas-d          #+#    #+#             */
/*   Updated: 2023/08/29 21:12:59 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line_to_write;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	line_to_write = NULL;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (fd >= 0 && fd <= FOPEN_MAX)
			ft_buffer_clear(buffer[fd]);
		return (NULL);
	}
	while (*buffer[fd] != 0 || read(fd, buffer[fd], BUFFER_SIZE) > 0)
	{
		line_to_write = ft_strjoin(line_to_write, buffer[fd]);
		if (ft_newline_check(buffer[fd]))
			break ;
	}
	return (line_to_write);
}
