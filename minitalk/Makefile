CLIENT	= client

SERVER	= server

CFLAGS	= -g -Wall -Werror -Wextra

LIBFT_DIR	= ./libft/

OBJS	= $(SRCS:.c=.o)

all: $(CLIENT) $(SERVER)

$(CLIENT) :
	make -C $(LIBFT_DIR)
	cc $(CFLAGS) client.c libft/libft.a -o $(CLIENT)

$(SERVER) :
	make -C $(LIBFT_DIR)
	cc $(CFLAGS) server.c libft/libft.a -o $(SERVER)

.PHONY: all clean fclean re

clean:
	rm -f $(CLIENT) $(SERVER)
	rm -f $(LIBFT_DIR)*.o

fclean: clean
	rm -f $(LIBFT_DIR)*.a

re: fclean all