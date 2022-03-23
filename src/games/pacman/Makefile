##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## .
##

FLAGS = -Wall -Wextra -Werror -g3 -fPIC -shared -Iinclude

NAME = arcade_pacman.so

DEST = ../../../lib

CC = g++

SRC = 	src/Core.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	$(CC) -o $(DEST)/$(NAME) $(SRC) $(FLAGS)
	@make clean

standalone:
	$(CC) -o pacman $(SRC) main.cpp -Wall -Wextra -Werror -g3 -lncurses;
	@make clean
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
