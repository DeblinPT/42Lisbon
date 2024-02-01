/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:06:27 by adimas-d          #+#    #+#             */
/*   Updated: 2024/02/01 20:39:10 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pos_calc(t_data *model, int i)
{
	t_vector_3d	rot;
	t_vector_3d	lala;
	t_vector_3d	orig;

	orig = model->to_draw[i];
	rot = model->camara.rotation;
	lala.x = orig.x * cos(rot.y) * cos(rot.z)
		+ orig.y * (cos(rot.z) * sin(rot.x) * sin(rot.y) - cos(rot.x)
			* sin(rot.z)) + orig.z * (cos(rot.x) * cos(rot.z) * sin(rot.y)
			+ sin(rot.x) * sin(rot.z));
	lala.y = orig.x * (cos(rot.y) * sin(rot.z))
		+ orig.y * (cos(rot.x) * cos(rot.z) + sin(rot.x) * sin(rot.y)
			* sin(rot.z)) + orig.z * (-cos(rot.z) * sin(rot.x) + cos(rot.x)
			* sin(rot.y) * sin(rot.z));
	lala.x += model->camara.position.x;
	lala.y += model->camara.position.y;
	lala.z = orig.z;
	lala.color = orig.color;
	model->to_draw[i] = lala;
}

void	ft_apply_camera(t_data *model)
{
	int	i;

	i = 0;
	while (i < model->column_count * model->line_count)
	{
		model->to_draw[i].x *= model->camara.zoom;
		model->to_draw[i].y *= model->camara.zoom;
		model->to_draw[i].z *= model->camara.z_factor;
		i++;
	}
	i = 0;
	while (i < model->column_count * model->line_count)
	{
		ft_pos_calc(model, i);
		i++;
	}
}

void	ft_dots(t_data *model)
{
	int			c;
	int			l;
	int			i;

	c = 0;
	l = 0;
	while (l < model->line_count)
	{
		i = (l * model->column_count);
		while (c < model->column_count)
		{
			if (c < model->column_count - 1)
				ft_connect_dots(model, (c + i), (c + i + 1));
			if (l < model->line_count - 1)
				ft_connect_dots(model, (c + i), (c + i + model->column_count));
			c++;
		}
		c = 0;
		l++;
	}
}

void	ft_draw_grid(t_data *model)
{
	t_vector_3d	*to_draw;

	to_draw = (t_vector_3d *)malloc(sizeof(t_vector_3d) * model->column_count
			* model->line_count);
	model->to_draw = to_draw;
	to_draw = ft_memcpy(model->to_draw, model->matrix, sizeof(t_vector_3d)
			* model->column_count * model->line_count);
	ft_apply_camera(model);
	ft_dots(model);
	free(to_draw);
}

void	ft_creat_image(t_data *model, int x, int y)
{
	model->img.mlx_img = mlx_new_image(model->mlx, x, y);
	model->img.addr = mlx_get_data_addr(model->img.mlx_img,
			&model->img.bits_per_pixel, &model->img.line_length,
			&model->img.endian);
}
