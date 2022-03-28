##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## .
##

CXXFLAGS = -Wall -Wextra -Werror -g3 -I../../shared/ -shared -fPIC -lncurses

NAME = arcade_ncurses.so

DEST = ../../../lib

CC = g++

SRC = NcursesGraphicsLib.cpp \
	../../shared/operators.cpp \
	make.cpp \
	../../shared/csv.cpp

all: $(NAME)

$(NAME):
	$(CC) -o $(DEST)/$(NAME) $(SRC) $(CXXFLAGS)

clean:
	rm -rf

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
