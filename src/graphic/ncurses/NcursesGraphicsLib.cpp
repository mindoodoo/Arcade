/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/


#include "NcursesGraphicsLib.hpp"

NcursesGraphicsLib::NcursesGraphicsLib()
{
    initscr();
    raw();
    noecho();
    curs_set(0);
    halfdelay(1);
}

void NcursesGraphicsLib::display()
{
    refresh();
}

void NcursesGraphicsLib::showText(const std::string &text, int x, int y)
{
    mvaddstr(x, y, text.c_str());
}

NcursesGraphicsLib::~NcursesGraphicsLib()
{
    endwin();
}

void NcursesGraphicsLib::drawTile(const std::string &path, int x, int y, int h, int w)
{
    this->drawTile(x, y, h, w, '#');
}

void NcursesGraphicsLib::drawTile(int x, int y, int h, int w, char c)
{
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w * 2; j += 2) {
            mvaddch(y + i, x + j, c);
            if (i + 1 < w)
                mvaddch(y + i + 1, x + j, ' ');
        }
    }
}

void NcursesGraphicsLib::flush()
{
    clear();
}

void NcursesGraphicsLib::event()
{
}
