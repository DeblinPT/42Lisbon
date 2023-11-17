/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:47:18 by adimas-d          #+#    #+#             */
/*   Updated: 2023/08/29 22:37:24 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line_to_write;
	static char	buffer[BUFFER_SIZE + 1];

	line_to_write = NULL;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		ft_buffer_clear(buffer);
		return (NULL);
	}
	while (*buffer != 0 || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line_to_write = ft_strjoin(line_to_write, buffer);
		if (ft_newline_check(buffer))
			break ;
	}
	return (line_to_write);
}

/*int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	fd = open("file.txt", O_RDONLY);
	while ((line = get_next_line(fd)) > 0)
	{
		printf("Line %d: -> %s\n", i++, line);
		free(line);
	}
	close(fd);
	return (0);
}*/
