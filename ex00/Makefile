SRC = ../srcs/main.cpp
NAME = templates
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
    c++ -Wall -Wextra -Werror -std=c++98 $(OBJ) -o $(NAME)

# Rule to compile .cpp files to .o files
../srcs/%.o: ../srcs/%.cpp
    c++ -Wall -Wextra -Werror -std=c++98 -c $< -o $@

clean:
    rm -rf $(OBJ)

fclean: clean
    rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

