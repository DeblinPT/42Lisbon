/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:19:15 by adimas-d          #+#    #+#             */
/*   Updated: 2024/02/01 21:07:08 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_first_line_count(int fd)
{
	int		count;
	char	*line;

	count = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = ft_get_next_line(fd);
	}
	return (count);
}

int	ft_count_columns(char **line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i] != NULL)
	{
		i++;
		count++;
	}
	return (count);
}

int	ft_count_columns2(char **line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i] != NULL)
	{
		free(line[i]);
		i++;
		count++;
	}
	return (count);
}

void	ft_build(t_data *model, char *av, int fd)
{
	t_vector_3d	*matrix;

	model->column_count = ft_need_free(fd);
	model->line_count = ft_first_line_count(open(av, O_RDONLY));
	matrix = (t_vector_3d *)malloc(sizeof(t_vector_3d) * model->column_count
			* model->line_count);
	model->matrix = matrix;
	ft_read_map(model, matrix, av);
}

int	main(int ac, char **av)
{
	t_data		model;
	int			fd;

	model.width = 1500;
	model.hight = 800;
	model.column_count = 0;
	model.line_count = 0;
	if (ac != 2)
		ft_error_handling(1);
	else if (ft_compare(av[1], ".fdf"))
		ft_error_handling(2);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error_handling(2);
	else
		ft_build(&model, av[1], fd);
	ft_creat_window(&model);
	ft_draw_grid(&model);
	mlx_put_image_to_window(model.mlx, model.mlx_window,
		model.img.mlx_img, 0, 0);
	mlx_key_hook(model.mlx_window, ft_key_push, &model);
	mlx_hook(model.mlx_window, 17, 0, ft_close_window, &model);
	mlx_loop(model.mlx);
}
