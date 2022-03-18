##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## wtf?
##

GRAPH_SRC = src/graphic

GRAPH_DEST = lib

CORE_SRC =  src/core/main.cpp\
			src/graphic/LdLoader.cpp

CORE_OBJ = $(CORE_SRC:.c=.o)

CORE_NAME = arcade

CFLAGS = -Wall -Wextra -std=c++2a -fno-gnu-unique -ldl

DYN_LIB_FLAGS = -Wall -Wextra -shared -fPIC

SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system $(DYN_LIB_FLAGS)

NCURSES_FLAGS = -lncurses $(DYN_LIB_FLAGS)

SDL2_FLAGS = -lSDL2 -lSDL2main $(DYN_LIB_FLAGS)

all:    core games graphicals

core: 	$(CORE_OBJ)
		g++ $(CORE_OBJ) $(CFLAGS) -o $(CORE_NAME) -I include;
		@make clean

games:

graphicals:
	g++ $(GRAPH_SRC)/sfml/SfmlGraphicsLib.cpp -o $(GRAPH_DEST)/arcade_sfml.so $(SFML_FLAGS)
	gcc $(GRAPH_SRC)/sdl2/Sdl2GraphicsLib.cpp -o $(GRAPH_DEST)/arcade_sdl2.so $(SDL2_FLAGS)
	g++ $(GRAPH_SRC)/ncurses/NcursesGraphicsLib.cpp -o $(GRAPH_DEST)/arcade_ncurses.so $(NCURSES_FLAGS)

clean:
		find -regex ".*/.*\.o" -delete;

fclean: clean;
		find -regex "./$(NAME)" -delete;
		find -regex ".*\.so" -delete;

re: fclean
	@make $(NAME)

.PHONY: all clean
