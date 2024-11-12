NAME	= philo

CFLAGS	= -Wall -Werror -Wextra -g

SRCS	= main.c start_sim.c get_ready.c get_set.c safe_functions.c parsing.c monitor.c utils.c utils2.c 

OBJS	= $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	@cc $(CFLAGS) $(OBJS) -o $(NAME)
	@echo philo compiled.

%.o : %.c
	@cc -c $(CFLAGS) $< -o $@

.PHONY: all bonus clean fclean re teste

all: $(NAME)

clean:                                                                                                               
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all