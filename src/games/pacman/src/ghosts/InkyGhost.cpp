/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "InkyGhost.hpp"

Pacman::InkyGhost::InkyGhost(Pacman::Terrain *scene, IGraphicsLib **gfx, Player *pacman)
    : BaseGhost(scene, gfx, pacman)
{
    this->_x = 12;
    this->_y = 11;
    this->_initialSleepSeconds = 10;
    this->_id = INKY;

    this->_movementTiles = {
        INKY_GHOST_RIGHT,
        INKY_GHOST_LEFT,
        INKY_GHOST_BACKFACING,
        INKY_GHOST_BACKFACING
    };
    this->_movementTile = this->_movementTiles.frontfacing;
}

void Pacman::InkyGhost::move(size_t x, size_t y, size_t blinkyX, size_t blinkyY)
{
    y += 2;

    std::pair<int, int> vector = {(blinkyX - x) * 2, (blinkyY - y) * 2};

    this->masterMove(blinkyX + vector.first, blinkyY + vector.second);
}
