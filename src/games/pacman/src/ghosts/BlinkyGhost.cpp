/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "BlinkyGhost.hpp"

Pacman::BlinkyGhost::BlinkyGhost(Terrain *scene, IGraphicsLib **gfx, Player *pacman)
    : BaseGhost(scene, gfx, pacman)
{
    this->_x = 9;
    this->_y = 11;
    this->_initialSleepSeconds = 10;
    this->_id = BLINKY;

    this->_movementTiles = {
        BLINKY_GHOST_RIGHT,
        BLINKY_GHOST_LEFT,
        BLINKY_GHOST_BACKFACING,
        BLINKY_GHOST_BACKFACING
    };

    this->_movementTile = this->_movementTiles.frontfacing;
}

void Pacman::BlinkyGhost::move(size_t x, size_t y)
{
    this->masterMove(x, y);
}
