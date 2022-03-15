##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## wtf?
##

FILES = src/main.cpp

SRC =  $(FILES)

OBJ = $(SRC:.c=.o)

NAME = arcade

CFLAGS = -Wall -Wextra -std=c++20 -fno-gnu-unique

all:    $(NAME)

$(NAME): 	$(OBJ)
			g++ $(OBJ) $(CFLAGS) -o $(NAME) -I include;
			@make clean

clean:
		find -regex ".*/.*\.o" -delete;

fclean: clean;
		find -regex "./$(NAME)" -delete;
		find -regex ".*/$(TEST_NAME)-.*" -delete;

re: fclean
	@make $(NAME)

.PHONY: all clean
