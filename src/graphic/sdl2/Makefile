##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## .
##

CXXFLAGS = -Wall -Wextra -Werror -g3 -I../../shared -shared -fPIC \
	-g3 -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2main

NAME = arcade_sdl2.so

DEST = ../../../lib

CC = g++

SRC = Sdl2GraphicsLib.cpp \
	../../shared/operators.cpp \
	make.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(DEST)/$(NAME) $(SRC) $(CXXFLAGS)
	make clean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
