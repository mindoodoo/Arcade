/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <ncurses.h>


#include "include/NibblerMacros.hpp"

void mockDrawTile(int tile, int x, int y)
{

    char c;

    switch (tile) {
        case NIBBLER_HEAD:
            c = 'h';
            break;
        case NIBBLER_BODY:
            c = 'b';
            break;
        case NIBBLER_TAIL:
            c = 't';
            break;
        case TERRAIN_WALL:
            c = '@';
            break;
        case TERRAIN_FLOOR:
            c = ' ';
            break;
        case ITEM_FRUIT:
            c = 'a';
            break;
    }

    mvaddch(y, x * 2, c);
}


void mockInitGfxLib()
{

    initscr();
    raw();
    noecho();
    curs_set(0);
    halfdelay(1);
}

void mockShowText(const std::string &text, int x, int y)
{
    mvaddstr(y, x, text.c_str());
}
