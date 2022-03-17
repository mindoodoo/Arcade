/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "NcursesGraphicsLib.hpp"
#include <string>

void draw_street(IGraphicsLib *lib, int x, int y)
{
    lib->drawTile(x, y, 8, 2, '#');
    lib->drawTile(x + 6, y, 8, 2, '#');
}

int main(int argc, char *argv[])
{

    auto glib = new NcursesGraphicsLib();

    int i = 1;

    int x = 130;
    int y = 20;

    while (i) {
        glib->flush();
        glib->showText("Score: " + std::to_string(COLS), 2, 2);
        glib->showText("Score: " + std::to_string(LINES), 3, 2);
        glib->showText("Score: " + std::to_string(i), LINES / 2, COLS / 2);
        i++;
        draw_street(glib, x, y);
        glib->display();

        switch (getch()) {
            case 'z':
                y--;
                break;
            case 's':
                y++;
                break;
            case 'd':
                x++;
                break;
            case 'q':
                x--;
                break;
            case 'x':
                i = 0;
                break;
        }
    }
    return 0;
}
