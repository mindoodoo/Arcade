/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "PinkyGhost.hpp"
#include "GhostManager.hpp"

Pacman::PinkyGhost::PinkyGhost(Terrain *scene, IGraphicsLib **gfx, Player *pacman)
    : BaseGhost(scene, gfx, pacman)
{
    this->start = {10, 11};
    this->_x = this->start.first;
    this->_y = this->start.second;
    this->_initialSleepSeconds = 15;
    this->_id = PINKY;
    this->_normalSpeed = 250;
    this->_currentSpeed = this->_normalSpeed;
    this->moveTimer = std::chrono::system_clock::now();
    this->_movementTiles = {
        PINKY_GHOST_RIGHT,
        PINKY_GHOST_LEFT,
        PINKY_GHOST_BACKFACING,
        PINKY_GHOST_FRONTFACING
    };
    this->_movementTile = this->_movementTiles.frontfacing;
}

void Pacman::PinkyGhost::move(size_t x, size_t y)
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - this->moveTimer).count() >= this->_normalSpeed) {
        std::pair<char, char> dir = this->_pacman->getDirection();
        this->masterMove(x + dir.first * 4, y + dir.second * 4);
        this->moveTimer = now;
    }
}
