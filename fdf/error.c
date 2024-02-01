/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:53:06 by adimas-d          #+#    #+#             */
/*   Updated: 2024/02/01 21:09:15 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_handling(int error)
{
	if (error == 1)
	{
		ft_printf("This program only accepts 2 arguments.\n");
		exit(0);
	}
	else if (error == 2)
	{
		ft_printf("Wrong file format or file doesn't exist.\n");
		exit(0);
	}
	else if (error == 3)
	{
		ft_printf("File doesn't have a square or rectangular map.\n");
		exit(0);
	}
}

int	ft_need_free(int fd)
{
	char	*line;
	char	**split;
	int		columns;

	line = ft_get_next_line(fd);
	split = ft_split(line, ' ');
	free(line);
	columns = ft_count_columns2(split);
	free(split);
	return (columns);
}

int	ft_compare(const char *big, const char *little)
{
	size_t	j;
	size_t	i;
	size_t	len;

	j = 0;
	i = 0;
	len = ft_strlen(big) - 4;
	while (big[len + i] == little[j] && little[j] && big[len + i])
	{
		if (little[j + 1] == 0)
			return (0);
		j++;
		i++;
	}
	return (1);
}
