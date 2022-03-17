##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## wtf?
##

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

clean:
		find -regex ".*/.*\.o" -delete;

fclean: clean;
		find -regex "./$(NAME)" -delete;
		find -regex ".*/$(TEST_NAME)-.*" -delete;

re: fclean
	@make $(NAME)

.PHONY: all clean
