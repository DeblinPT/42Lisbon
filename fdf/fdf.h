/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:19:08 by adimas-d          #+#    #+#             */
/*   Updated: 2024/02/01 21:00:54 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx.h"
# include "libftcompleto/libft.h"
# include <math.h>
# include <stdlib.h>

# define ESC_KEY 65307
# define UP_ARROW_KEY 65362
# define DOWN_ARROW_KEY 65364
# define LEFT_ARROW_KEY 65361
# define RIGHT_ARROW_KEY 65363
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define Q_KEY 113
# define E_KEY 101
# define R_KEY 114
# define F_KEY 102
# define Z_KEY 122
# define X_KEY 120

typedef struct s_vector_3d
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_vector_3d;

typedef struct s_camara
{
	t_vector_3d	position;
	t_vector_3d	rotation;
	float		zoom;
	float		z_factor;
}				t_camara;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_window;
	t_img		img;
	int			column_count;
	int			line_count;
	int			width;
	int			hight;
	t_vector_3d	*matrix;
	t_vector_3d	*to_draw;
	t_camara	camara;
	float		x_step;
	float		y_step;
	float		x;
	float		y;
	int			color;
}				t_data;

/* DRAW */
void	ft_pos_calc(t_data *model, int i);
void	ft_apply_camera(t_data *model);
void	ft_dots(t_data *model);
void	ft_draw_grid(t_data *model);
void	ft_creat_image(t_data *model, int x, int y);

/* DRAW2 */
void	my_mlx_pixel_put(t_data *model, int x, int y, int color);
void	ft_set_values(t_data *model, int xy, int x1y1);
void	ft_step(t_data *model, float z, float z1, float step_max);
void	ft_connect_dots(t_data *model, int xy, int x1y1);

/* ERROR*/
void	ft_error_handling(int error);
int		ft_need_free(int fd);
int		ft_compare(const char *big, const char *little);

/* MAIN */
int		ft_first_line_count(int fd);
int		ft_count_columns(char **line);
int		ft_count_columns2(char **line);
void	ft_build(t_data *model, char *av, int fd);

/* MOVEMENT */
int		ft_key_push(int keycode, t_data *model);
void	ft_rotation(int keycode, t_data *model);

/* READ_MAP */
void	ft_parse_line(t_data *model, t_vector_3d *matrix, char *line, int yi);
void	ft_read_map(t_data *model, t_vector_3d *matrix, char *av);

/* WINDOW */
void	ft_creat_window(t_data *model);
int		ft_close_window(t_data *model);

#endif