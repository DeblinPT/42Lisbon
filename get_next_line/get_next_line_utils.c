/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:38:19 by adimas-d          #+#    #+#             */
/*   Updated: 2023/08/29 20:12:31 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_buffer_clear(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		buffer[i++] = '\0';
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		if (s2[j] == '\n')
			break ;
		j++;
	}
	free (s1);
	new[i] = '\0';
	return (new);
}

int	ft_newline_check(char *buffer)
{
	int	has_new_line;
	int	i;
	int	j;

	has_new_line = 0;
	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (has_new_line)
		{
			buffer[j] = buffer[i];
			j++;
		}
		if (buffer[i] == '\n')
			has_new_line = 1;
		buffer[i] = 0;
		i++;
	}
	return (has_new_line);
}
