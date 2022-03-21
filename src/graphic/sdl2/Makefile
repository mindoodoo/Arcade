##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## .
##

CXXFLAGS = -Wall -Wextra -Werror -g3 -I../../shared_interfaces -shared -fPIC \
	-g3 -lSDL2 -lSDL2main

NAME = sdllib.so

DEST = ../../../lib

CC = g++

SRC = Sdl2GraphicsLib.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(DEST)/$(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re