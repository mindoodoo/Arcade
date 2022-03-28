/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "src/GameCore.hpp"

#include "../MockGfx.hpp"

int main()
{
    IGraphicsLib *gfx = new MockGfx();

    Core *core = new Core(&gfx);

    do {
        refresh();
    } while (core->frame() != QUIT_SIGNAL);
}
