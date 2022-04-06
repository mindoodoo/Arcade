##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## .
##

DEFAULT_FLAGS = -Wall -Wextra -g3

FLAGS = $(DEFAULT_FLAGS) -fPIC -shared -Iinclude

NAME = arcade_pacman.so

DEST = ../../../lib

CC = g++

SRC = 	src/GameCore.cpp\
		src/Level.cpp\
		src/Terrain.cpp\
		src/Player.cpp\
		src/Astar.cpp\
		src/BaseGhost.cpp\
		src/make.cpp\
		../BaseGameCore.cpp

STDL_SRC = 	$(SRC)\
			main.cpp\
			../MockGfx.cpp

STDL_FLAGS = $(DEFAULT_FLAGS) -lncurses -Iinclude;

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME):
	$(CC) -o $(DEST)/$(NAME) $(SRC) $(FLAGS)
	@make clean

standalone:
	$(CC) -o arcade_pacman $(STDL_SRC) $(STDL_FLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
