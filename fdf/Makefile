NAME	= fdf

CFLAGS	= -g -Wall -Werror -Wextra

SRCS	= draw.c draw2.c error.c main.c movement.c read_map.c window.c

LIBFT_DIR	= ./libftcompleto/

MLX_DIR	=./minilibx-linux/

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@cc $(CFLAGS) $(OBJS) -I./libftcompleto -I./minilibx-linux -L./minilibx-linux -lmlx -lX11 -lXext -lm ./libftcompleto/libft.a -o $(NAME)
	@echo FDF compiled.

%.o : %.c
	@cc -c -g $(CFLAGS) $< -o $@

.PHONY: all bonus clean fclean re teste

all: $(NAME)

#bonus: fclean $(NAME)
#	make -C $(LIBFT_DIR)
#	ar -crs $(NAME) $(BONUS)

clean:                                                                                                               
	@rm -f $(OBJS) $(BONUS_OBJS)
	@rm -f $(LIBFT_DIR)*.o
	@make clean -C $(MLX_DIR)
	@echo FDF Gone!

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@rm -f $(LIBFT_DIR)*.a
	@echo FDF REALY GONE!

re: fclean all

#cc -g -I./libftcompleto -I./mlx_linux -L./mlx_linux -lmlx -lX11 -lXext -lm fdf.c ./libftcompleto/libft.a
#cc -g fdf.c -I./libftcompleto -I./mlx_linux -L./mlx_linux -lmlx -lX11 -lXext -lm ./libftcompleto/libft.a