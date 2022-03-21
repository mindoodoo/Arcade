##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## wtf?
##

CORE_SRC =  src/core/main.cpp \
	# src/loader/LdLoader.cpp

CORE_OBJ = $(CORE_SRC:.c=.o)

CORE_NAME = arcade

CFLAGS = -Wall -Wextra -fno-gnu-unique -ldl

all: core games graphicals

core: $(CORE_OBJ)
	g++ $(CORE_OBJ) $(CFLAGS) -o $(CORE_NAME) -I include;
	@make clean

games:
	echo "No game libraries to compile."

graphicals:
	make -C ./src/graphic/ncurses
	make -C ./src/graphic/sdl2
	make -C ./src/graphic/sfml

clean:
	find -regex ".*/.*\.o" -delete;

fclean: clean;
	find -regex "./$(NAME)" -delete;
	find -regex ".*\.so" -delete;

re: fclean
	@make $(NAME)

.PHONY: all clean
