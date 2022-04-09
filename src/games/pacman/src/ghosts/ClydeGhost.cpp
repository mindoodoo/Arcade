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
    this->_normalSpeed = 250;
    this->_currentSpeed = this->_normalSpeed;
    this->moveTimer = std::chrono::system_clock::now();
    this->_movementTiles = {
        CLYDE_GHOST_RIGHT,
        CLYDE_GHOST_LEFT,
        CLYDE_GHOST_BACKFACING,
        CLYDE_GHOST_FRONTFACING
    };

    this->_movementTile = this->_movementTiles.frontfacing;
}

void Pacman::ClydeGhost::move(size_t x [[maybe_unused]], size_t y [[maybe_unused]])
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - this->moveTimer).count() >= this->_normalSpeed) {
        if (this->_path.empty()) {
            coordinates_t randLocation = this->_scene->randomLocation();
            this->masterMove(randLocation.first, randLocation.second);
        } else {

            this->_y = this->_path.front().first < this->_scene->getHeight() ? this->_path.front().first : 1;
            this->_x = this->_path.front().second < this->_scene->getWidth() ? this->_path.front().second : 1;
            this->_path.pop_front();

            this->setMovementTile();
        }
        this->moveTimer = now;
    }
}
