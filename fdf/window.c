/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:03:14 by adimas-d          #+#    #+#             */
/*   Updated: 2024/02/01 20:42:34 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_creat_window(t_data *model)
{
	model->mlx = mlx_init();
	model->mlx_window = mlx_new_window(model->mlx, model->width,
			model->hight, "fdf");
	ft_creat_image(model, model->width, model->hight);
	model->camara.position.x = model->width / 2;
	model->camara.position.y = model->hight / 2;
	model->camara.rotation.x = 0.523599;
	model->camara.rotation.y = 0.523599;
	model->camara.rotation.z = 0.1;
	model->camara.z_factor = 4;
	model->camara.zoom = (model->width / model->column_count) / 2;
}

int	ft_close_window(t_data *model)
{
	free (model->matrix);
	mlx_destroy_window(model->mlx, model->mlx_window);
	mlx_destroy_image(model->mlx, model->img.mlx_img);
	mlx_destroy_display(model->mlx);
	free(model->mlx);
	exit (0);
}
