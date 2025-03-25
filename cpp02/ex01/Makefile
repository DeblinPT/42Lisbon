NAME = fixed

FLAGS = -g -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp

OBJ = $(SRCS:.cpp=.o)

%.o : %.cpp
	c++ $(FLAGS) -c -o $@ $<

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all