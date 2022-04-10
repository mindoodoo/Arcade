##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## .
##

DEFAULT_FLAGS = -Wall -Wextra -g3

FLAGS = $(DEFAULT_FLAGS) -fPIC -shared -Iinclude

NAME = arcade_nibbler.so

DEST = ../../../lib

CC = g++

SRC = 	src/GameCore.cpp \
		src/Level.cpp \
		src/Player.cpp \
		src/Terrain.cpp \
		src/Fruit.cpp \
		src/MegaFruit.cpp \
		src/Item.cpp \
		src/make.cpp \
		../../shared/mapParser.cpp \
		../GameErrors.cpp \
		../BaseGameCore.cpp \
		../../shared/csv.cpp \
		../../shared/gfxParser.cpp

STDL_SRC = 	$(SRC)\
			main.cpp\
			../MockGfx.cpp

STDL_FLAGS = $(DEFAULT_FLAGS) -lncurses -Iinclude;


all: $(NAME)

$(NAME):
	$(CC) -o $(DEST)/$(NAME) $(SRC) $(FLAGS)
	@make clean

standalone:
	$(CC) -o arcade_nibbler $(STDL_SRC) $(STDL_FLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
