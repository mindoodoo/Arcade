/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/


#include <iostream>
#include "BaseGhost.hpp"

Pacman::BaseGhost::BaseGhost(Pacman::Terrain *scene, IGraphicsLib **gfx, Player *pacman)
{
    this->_scene = scene;
    this->_gfx = gfx;
    this->_pacman = pacman;
    this->setState(GhostState::SLEEPING);
    this->stateChangeTimer = std::chrono::system_clock::now();
    this->_initialSleepSeconds = 10;
    this->_huntedSpeed = 325;
    this->_retreatingSpeed = 450;
    this->_normalSpeed = 250;
    this->_currentSpeed = this->_normalSpeed;
    this->_vulnerable = false; // to check if ghost has already been eaten
}

void Pacman::BaseGhost::setState(Pacman::GhostState state)
{
    if (state == GhostState::DEFEATED && !this->_vulnerable)
        return;

    this->_state = state;

    if (state == GhostState::HUNTED)
        this->_currentSpeed = this->_huntedSpeed;
    if (state == GhostState::HUNTING)
        this->_currentSpeed = this->_normalSpeed;
    if (state == GhostState::DEFEATED) {
        this->_vulnerable = false;
        this->returnToSpawn();
        this->_currentSpeed = this->_retreatingSpeed;
    }

    this->stateChangeTimer = std::chrono::system_clock::now();
}

void Pacman::BaseGhost::masterMove(size_t x, size_t y)
{
    if (this->_state == GhostState::SLEEPING)
        return;

    coordinates_t currLoc = {this->_x, this->_y};

    if (this->_state != GhostState::DEFEATED) {
        if (this->_pacman->getState() == Player::State::SUPER) {
            if (this->_path.empty()) {
                coordinates_t randomLocation = this->_scene->randomLocation();
                std::deque<coordinates_t> path = calculateAStar(currLoc, randomLocation, this->_scene->getMap());

                if (!path.empty())
                    this->_path = path;
                if (this->_path.empty())
                    return;
            }
        } else {
            std::deque<coordinates_t> path = calculateAStar(currLoc, {x, y}, this->_scene->getMap());

            if (!path.empty())
                this->_path = path;
            if (this->_path.empty())
                return;
        }
    }

    if (this->_path.front().first >= this->_scene->getHeight() ||
        this->_path.front().second >= this->_scene->getWidth()) {
        this->_x = this->start.first;
        this->_y = this->start.second;
    } else {
        this->_y = this->_path.front().first;
        this->_x = this->_path.front().second;
    }
    this->_path.pop_front();

    if (this->_state == GhostState::DEFEATED) {
        // changing path in setState
        if (this->_path.empty()) {
            this->_state = GhostState::HUNTING;
        }
    }
    this->setMovementTile();
}

void Pacman::BaseGhost::draw()
{
    GFX->drawTile(this->_movementTile, this->_x, this->_y);
}

void Pacman::BaseGhost::move(size_t x, size_t y)
{
    this->masterMove(x, y);
}

int Pacman::BaseGhost::getID() const
{
    return this->_id;
}

std::pair<size_t, size_t> Pacman::BaseGhost::getLocation()
{
    return {this->_x, this->_y};
}

bool Pacman::BaseGhost::setActive()
{
    if (this->_state == GhostState::SLEEPING) {
        std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
        if (std::chrono::duration_cast<std::chrono::seconds>(now - this->stateChangeTimer).count() >=
            this->_initialSleepSeconds) {
            this->setState(GhostState::HUNTING);
            return true;
        } else
            this->_movementTile = this->_movementTiles.frontfacing;
    }
    return false;
}

Pacman::GhostState Pacman::BaseGhost::getState() const
{
    return this->_state;
}

void Pacman::BaseGhost::setMovementTile()
{
    if (this->_state == GhostState::HUNTED)
        this->_movementTile = GHOST_HUNTED;
    else if (this->_state == GhostState::DEFEATED)
        this->_movementTile = GHOST_DEFEATED;
    else if (!this->_path.empty() && this->_x < this->_path.front().second)
        this->_movementTile = this->_movementTiles.right;
    else if (!this->_path.empty() && this->_x >= this->_path.front().second)
        this->_movementTile = this->_movementTiles.left;
    else if (!this->_path.empty() && this->_y < this->_path.front().first)
        this->_movementTile = this->_movementTiles.backfacing;
    else if (!this->_path.empty() && this->_y <= this->_path.front().first)
        this->_movementTile = this->_movementTiles.frontfacing;
}

void Pacman::BaseGhost::returnToSpawn()
{
    this->_path = calculateAStar(this->getLocation(), this->start, this->_scene->getMap());
}

void Pacman::BaseGhost::setVulnerable(bool vulnerable)
{
    this->_vulnerable = vulnerable;
}

bool Pacman::BaseGhost::getVulnerable() const
{
    return this->_vulnerable;
}
