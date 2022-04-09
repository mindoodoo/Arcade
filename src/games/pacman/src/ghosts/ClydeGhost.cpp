/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "ClydeGhost.hpp"

Pacman::ClydeGhost::ClydeGhost(Terrain *scene, IGraphicsLib **gfx, Player *pacman)
    : BaseGhost(scene, gfx, pacman)
{
    this->start = {13, 11};
    this->_x = start.first;
    this->_y = start.second;
    this->_initialSleepSeconds = 10;
    this->_id = CLYDE;

    this->_movementTiles = {
        CLYDE_GHOST_RIGHT,
        CLYDE_GHOST_LEFT,
        CLYDE_GHOST_BACKFACING,
        CLYDE_GHOST_FRONTFACING
    };

    this->_movementTile = this->_movementTiles.frontfacing;
}

void Pacman::ClydeGhost::move(size_t x, size_t y)
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    if (this->_state == GhostState::SLEEPING) {
        if (std::chrono::duration_cast<std::chrono::seconds>(now - this->stateChangeTimer).count() >=
            this->_initialSleepSeconds) {
            this->setState(GhostState::HUNTING);
        } else
            this->_movementTile = this->_movementTiles.frontfacing;
        return;
    }

    if (this->_path.empty()) {
        coordinates_t randLocation = this->_scene->randomLocation();
        this->_path = calculateAStar(coordinates_t{this->_y, this->_x},
                                     coordinates_t{randLocation.second, randLocation.first},
                                     this->_scene->getMap());
        if (this->_path.empty())
            return;
    }

    if (this->_x < this->_path.front().second)
        this->_movementTile = this->_movementTiles.right;
    else if (this->_x > this->_path.front().second)
        this->_movementTile = this->_movementTiles.left;
    else if (this->_y < this->_path.front().first)
        this->_movementTile = this->_movementTiles.backfacing;
    else if (this->_y > this->_path.front().first)
        this->_movementTile = this->_movementTiles.frontfacing;
    this->_y = this->_path.front().first < this->_scene->getHeight() ? this->_path.front().first : 1;
    this->_x = this->_path.front().second < this->_scene->getWidth() ? this->_path.front().second : 1;
    this->_path.pop_front();
}
