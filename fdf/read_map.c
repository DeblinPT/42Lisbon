/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:09:11 by adimas-d          #+#    #+#             */
/*   Updated: 2024/02/01 19:58:28 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parse_line(t_data *model, t_vector_3d *matrix, char *line, int yi)
{
	char		**temp;
	int			xi;
	int			columns;

	xi = 0;
	if (!line)
		return ;
	temp = ft_split(line, ' ');
	columns = ft_count_columns(temp);
	if (model->column_count != columns)
		ft_error_handling(3);
	while (temp[xi])
	{
		matrix[yi * columns + xi].x = (float)(xi - (model->column_count / 2));
		matrix[yi * columns + xi].y = (float)(yi - (model->line_count / 2));
		matrix[yi * columns + xi].z = (float)atoi(temp[xi]);
		if (matrix[yi * columns + xi].z == 0)
			matrix[yi * columns + xi].color = 0x00FFFFFF;
		else
			matrix[yi * columns + xi].color = 0x00FFFFFF + (0x00FF0000
					* matrix[yi * columns + xi].z);
		free(temp[xi]);
		xi++;
	}
	free(temp);
}

void	ft_read_map(t_data *model, t_vector_3d *matrix, char *av)
{
	int			fd;
	char		*line;
	int			yi;

	yi = 0;
	fd = open(av, O_RDONLY);
	line = ft_get_next_line(fd);
	while (line)
	{
		ft_parse_line(model, matrix, line, yi);
		free(line);
		line = ft_get_next_line(fd);
		yi++;
	}
}
