NAME	= libftprintf.a

CFLAGS	= -Wall -Werror -Wextra

LIBFT_DIR	= ./libft/

SRCS	= ft_print_addr.c ft_print_char.c ft_print_hex.c \
		ft_print_nbr.c ft_print_str.c ft_printf.c ft_bonus2.c \
		ft_size.c

SRCS_BONUS	= ft_print_addr.c ft_print_char.c ft_print_hex.c \
		ft_print_nbr.c ft_print_str.c ft_printf.c ft_flags_bonus.c \
		ft_size.c ft_width_bonus.c ft_bonus.c

OBJS	= $(SRCS:.c=.o)

BONUS_OBJS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	ar -crs $@ $^

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re teste

all: $(NAME)

bonus: $(BONUS_OBJS)
	make -C $(LIBFT_DIR)
	ar -crs $(NAME) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f $(LIBFT_DIR)*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)*.a

re: fclean

teste: teste.c libftprintf.a
	cc $(CFLAGS) -x c -I. -L. -lftprintf -Llibft -lft -g $<