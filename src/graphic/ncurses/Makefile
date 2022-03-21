##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## .
##

CXXFLAGS = -Wall -Wextra -Werror -g3 -I../../shared -shared -fPIC \
	-g3	-lncurses 

NAME = ncurseslib.so

DEST = ../../../lib

CC = g++

SRC = NcursesGraphicsLib.cpp

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