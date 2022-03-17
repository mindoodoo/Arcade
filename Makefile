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

CFLAGS = -Wall -Wextra -std=c++20 -fno-gnu-unique

all:    core games graphicals

core: 	$(CORE_OBJ)
		g++ $(CORE_OBJ) $(CFLAGS) -o $(CORE_NAME) -I include;
		@make clean

games:

graphicals:
	gcc $(GRAPH_SRC)/sfml/SfmlGraphicsLib.cpp  -Wall -Wextra -shared -fPIC -o $(GRAPH_DEST)/arcade_sfml.so
	#gcc $(GRAPH_SRC)/sdl2/Sdl2GraphicsLib.cpp  -Wall -Wextra -shared -fPIC -o $(GRAPH_DEST)/arcade_sdl2.so
	#gcc $(GRAPH_SRC)/ncurses/NcursesGraphicsLib.cpp  -Wall -Wextra -shared -fPIC -o $(GRAPH_DEST)/arcade_ncurses.so

clean:
		find -regex ".*/.*\.o" -delete;

fclean: clean;
		find -regex "./$(NAME)" -delete;
		find -regex ".*\.so" -delete;

re: fclean
	@make $(NAME)

.PHONY: all clean
