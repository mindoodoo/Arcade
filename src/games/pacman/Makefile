##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## .
##

FLAGS = -Wall -Wextra -Werror -g3 -lncurses

NAME = nibbler

DEST = ../../../lib

CC = g++

SRC = 	src/Core.cpp\
		src/GameManager.cpp\
		src/Nibbler.cpp\
		src/Terrain.cpp\
		src/Fruit.cpp\
		src/Item.cpp\
		../GameErrors.cpp

STANDALONE_SRC = 	$(SRC)\
					main.cpp\
					mockGfxLib.cpp

OBJ = $(STANDALONE_SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	#$(CC) -o $(DEST)/$(NAME) $(OBJ) $(FLAGS)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS)
	@make clean

standalone: $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
