##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## wtf?
##

CORE_SRC =  src/core/main.cpp \
	src/core/Core.cpp \
	src/core/loader/LdLoader.cpp\
	src/shared/ArcadeError.cpp

CORE_NAME = arcade

CFLAGS = -Wall -Wextra -fno-gnu-unique -ldl -I./src/shared/

all: core games graphicals

core:
	g++ $(CORE_SRC) $(CFLAGS) -o $(CORE_NAME)
	@make clean

games:
	make -C ./src/games/nibbler --no-print-directory

	make -C ./src/games/pacman --no-print-directory


graphicals:
	make -C ./src/graphic/ncurses --no-print-directory

	# make -C ./src/graphic/sdl2
	# make -C ./src/graphic/sfml

clean:
	find -regex ".*/.*\.o" -delete;

fclean: clean;
	find -regex "./$(NAME)" -delete;
	find -regex ".*/*.so" -delete;

re: fclean
	@make $(NAME) --no-print-directory

.PHONY: all clean
