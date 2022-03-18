/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "SfmlGraphicsLib.hpp"
#include <string>

void draw_street(IGraphicsLib *lib, int x, int y)
{
    lib->drawTile(x, y, 24, 6, '#');
    lib->drawTile(x + 25, y, 24, 6, '#');
}

int main(int argc, char *argv[])
{

    IGraphicsLib *glib = new SfmlGraphicsLib();

    int i = 1;

    int x = 130;
    int y = 20;

    while (i) {
        glib->flush();
        i++;
        draw_street(glib, x, y);
        glib->event();
        glib->display();
    }
    return 0;
}
