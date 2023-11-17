NAME	= libftprintf.a

NAME_BONUS	= libftprintf_bonus.a

CFLAGS	= -Wall -Werror -Wextra

LIBFT_DIR	= ./libft/

SRCS	= ft_flags_bonus.c ft_width_bonus.c ft_precision_bonus.c \
		ft_bonus.c ft_print_addr.c ft_print_char.c ft_print_base.c \
		ft_print_nbr.c ft_print_str.c ft_size.c ft_print_uns_nbr.c \
		ft_printf.c


SRCS_BONUS	= ft_flags_bonus.c ft_width_bonus.c ft_precision_bonus.c \
		ft_bonus.c ft_print_addr.c ft_print_char.c ft_print_base.c \
		ft_print_nbr.c ft_print_str.c ft_size.c ft_print_uns_nbr.c \
		ft_printf.c

OBJS	= $(SRCS:.c=.o)

BONUS_OBJS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	ar -rcs $@ $^ libft/*.o

$(NAME_BONUS) : $(OBJS_BONUS)
	make -C $(LIBFT_DIR)
	ar -rcs $@ $^ libft/*.o

%.o : %.c
	cc -c -g $(CFLAGS) $< -o $@

.PHONY: all bonus clean fclean re teste

all: $(NAME)

bonus: fclean $(NAME)
	make -C $(LIBFT_DIR)
	ar -crs $(NAME) $(BONUS)

clean:                                                                                                               
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f $(LIBFT_DIR)*.o

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	rm -f $(LIBFT_DIR)*.a

re: fclean all

#teste: teste.c libftprintf.a
#	cc -x c -I. $< -L. -lftprintf -Llibft -lft -g
#	./a.out

#		ft_flags_bonus.c ft_width_bonus.c ft_precision_bonus.c