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
}

void Pacman::BlinkyGhost::move(size_t x, size_t y)
{
    this->masterMove(x, y);
}
