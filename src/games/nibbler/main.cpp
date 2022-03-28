/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "src/GameCore.hpp"

#include "../MockGfx.hpp"
#include "include/NibblerMacros.hpp"

int main()
{
    MockGfx *gfx = new MockGfx();

    std::map<int, char> tileset;

    tileset[NIBBLER_HEAD] = 'h';
    tileset[NIBBLER_BODY] = 'b';
    tileset[NIBBLER_TAIL] = 't';
    tileset[ITEM_FRUIT] = 'a';
    tileset[TERRAIN_WALL] = '$';
    tileset[TERRAIN_FLOOR] = ' ';

    gfx->loadTileset(tileset);
    Nibbler::GameCore *core = new Nibbler::GameCore();

    IGraphicsLib *igfx = gfx;
    core->setGfx(&igfx);

    do {
        refresh();
    } while (core->frame() != QUIT_SIGNAL);

    delete gfx;
}
