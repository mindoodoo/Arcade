##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## .
##

CXXFLAGS = -Wall -Wextra -Werror -g3 -I../../shared -shared -fPIC \
	-lsfml-graphics -lsfml-window -lsfml-system

NAME = arcade_sfml.so

DEST = ../../../lib

CC = g++

SRC = SfmlGraphicsLib.cpp \
	../../shared/operators.cpp \
	make.cpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(DEST)/$(NAME) $(SRC) $(CXXFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
