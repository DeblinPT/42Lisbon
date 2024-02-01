/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:05:58 by adimas-d          #+#    #+#             */
/*   Updated: 2024/02/01 20:41:12 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_key_push(int keycode, t_data *model)
{
	if (keycode == ESC_KEY)
		ft_close_window(model);
	else if (keycode == UP_ARROW_KEY || keycode == W_KEY)
		model->camara.position.y -= 5;
	else if (keycode == DOWN_ARROW_KEY || keycode == S_KEY)
		model->camara.position.y += 5;
	else if (keycode == LEFT_ARROW_KEY || keycode == A_KEY)
		model->camara.position.x -= 5;
	else if (keycode == RIGHT_ARROW_KEY || keycode == D_KEY)
		model->camara.position.x += 5;
	else
		ft_rotation(keycode, model);
	mlx_destroy_image(model->mlx, model->img.mlx_img);
	ft_creat_image(model, model->width, model->hight);
	ft_draw_grid(model);
	mlx_clear_window(model->mlx, model->mlx_window);
	mlx_put_image_to_window(model->mlx, model->mlx_window,
		model->img.mlx_img, 0, 0);
	return (0);
}

void	ft_rotation(int keycode, t_data *model)
{
	if (keycode == Q_KEY)
		model->camara.rotation.y += 0.1;
	else if (keycode == E_KEY)
		model->camara.rotation.y -= 0.1;
	else if (keycode == R_KEY)
		model->camara.rotation.x += 0.1;
	else if (keycode == F_KEY)
		model->camara.rotation.x -= 0.1;
	else if (keycode == Z_KEY)
		model->camara.rotation.z += 0.1;
	else if (keycode == X_KEY)
		model->camara.rotation.z -= 0.1;
}
