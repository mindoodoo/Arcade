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
    this->start = {9, 11};
    this->_x = this->start.first;
    this->_y = this->start.second;
    this->_initialSleepSeconds = 10;
    this->_id = BLINKY;
    this->_normalSpeed = 250;
    this->_currentSpeed = this->_normalSpeed;
    this->moveTimer = std::chrono::system_clock::now();
    this->_movementTiles = {
        BLINKY_GHOST_RIGHT,
        BLINKY_GHOST_LEFT,
        BLINKY_GHOST_BACKFACING,
        BLINKY_GHOST_FRONTFACING
    };
    this->_movementTile = this->_movementTiles.frontfacing;
}

void Pacman::BlinkyGhost::move(size_t x, size_t y)
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - this->moveTimer).count() >= this->_currentSpeed) {
        this->masterMove(x, y);
        this->moveTimer = now;
    }
}
