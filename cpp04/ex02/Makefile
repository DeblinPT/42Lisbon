NAME = brain2

FLAGS = -g -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

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