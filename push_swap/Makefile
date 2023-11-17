NAME	= push_swap

CFLAGS	= -g -Wall -Werror -Wextra #-fsanitize=address

SRCS	= checks.c cost_to_a.c cost_to_b.c cost_utils.c main.c make_moves.c moves_in_list.c moves_r.c moves_rr.c moves_s_p.c sort.c stack_build.c

LIBFT_DIR	= ./libft/

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	cc $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

#%.o : %.c
#	cc -c -g $(CFLAGS) $< -o $@

.PHONY: all bonus clean fclean re teste

all: $(NAME)

#bonus: fclean $(NAME)
#	make -C $(LIBFT_DIR)
#	ar -crs $(NAME) $(BONUS)

clean:                                                                                                               
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f $(LIBFT_DIR)*.o

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	rm -f $(LIBFT_DIR)*.a

re: fclean all