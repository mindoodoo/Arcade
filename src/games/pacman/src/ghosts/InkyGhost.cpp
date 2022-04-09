/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "InkyGhost.hpp"

Pacman::InkyGhost::InkyGhost(Pacman::Terrain *scene, IGraphicsLib **gfx, Player *pacman, int *score)
    : BaseGhost(scene, gfx, pacman)
{
    this->start = {12, 11};
    this->_x = this->start.first;
    this->_y = this->start.second;
    this->_initialSleepSeconds = 10;
    this->_id = INKY;
    this->_normalSpeed = 250;
    this->_currentSpeed = this->_normalSpeed;
    this->moveTimer = std::chrono::system_clock::now();
    this->_movementTiles = {
        INKY_GHOST_RIGHT,
        INKY_GHOST_LEFT,
        INKY_GHOST_BACKFACING,
        INKY_GHOST_FRONTFACING
    };
    this->_movementTile = this->_movementTiles.frontfacing;
    this->_score = score;
}

void Pacman::InkyGhost::move(size_t x, size_t y, coordinates_t blinkyLoc)
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - this->moveTimer).count() >= this->_normalSpeed) {
        y += 2;

        std::pair<int, int> vector = {(blinkyLoc.first - x) * 2, (blinkyLoc.second - y) * 2};

        this->masterMove(blinkyLoc.first + vector.first, blinkyLoc.second + vector.second);
        this->moveTimer = now;
    }
}

bool Pacman::InkyGhost::setActive()
{
    if (*this->_score >= 30) {
        this->setState(GhostState::HUNTING);
        return true;
    }
    return false;
}
