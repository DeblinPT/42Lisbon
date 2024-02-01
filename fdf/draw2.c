/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:11:20 by adimas-d          #+#    #+#             */
/*   Updated: 2024/02/01 20:39:32 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *model, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && y > 0 && x < model->width && y < model->hight)
	{
		dst = model->img.addr + (y * model->img.line_length
				+ x * (model->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_set_values(t_data *model, int xy, int x1y1)
{
	model->color = model->to_draw[xy].color;
	model->x = model->to_draw[xy].x;
	model->y = model->to_draw[xy].y;
	model->x_step = (model->to_draw[x1y1].x - model->to_draw[xy].x);
	model->y_step = (model->to_draw[x1y1].y - model->to_draw[xy].y);
}

void	ft_step(t_data *model, float z, float z1, float step_max)
{
	model->x += model->x_step;
	model->y += model->y_step;
	if (z > z1)
		model->color += (0x0000ffff / step_max);
	if (z < z1)
		model->color -= (0x0000ffff / step_max);
}

void	ft_connect_dots(t_data *model, int xy, int x1y1)
{
	float	step_max;
	float	z;
	float	z1;
	int		i;

	i = 0;
	z = model->to_draw[xy].z;
	z1 = model->to_draw[x1y1].z;
	ft_set_values(model, xy, x1y1);
	if (fabs(model->x_step) >= fabs(model->y_step))
		step_max = fabs(model->x_step);
	else
		step_max = fabs(model->y_step);
	model->x_step /= step_max;
	model->y_step /= step_max;
	while (i <= step_max)
	{
		my_mlx_pixel_put(model, model->x, model->y, model->color);
		ft_step(model, z, z1, step_max);
		i += 1;
	}
}
