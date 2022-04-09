/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "GhostManager.hpp"

Pacman::GhostManager::GhostManager(Pacman::Terrain *scene, IGraphicsLib **gfx, Player *pacman, int *score)
{
    this->blinky = new BlinkyGhost(scene, gfx, pacman);
    this->pinky = new PinkyGhost(scene, gfx, pacman);
    this->inky = new InkyGhost(scene, gfx, pacman, score);
    this->clyde = new ClydeGhost(scene, gfx, pacman);

    this->_ghosts = {this->blinky, this->pinky, this->inky, this->clyde};

    this->score = score;

    this->pacman = pacman;

    this->_scene = scene;

    this->globalState = GhostState::HUNTING;
}

Pacman::BaseGhost *Pacman::GhostManager::getGhost(int id)
{
    switch (id) {
        case BLINKY:
            return this->blinky;
        case PINKY:
            return this->pinky;
        case INKY:
            return this->inky;
        case CLYDE:
            return this->clyde;
        default:
            return nullptr;
    }
}

void Pacman::GhostManager::move()
{
    size_t x = this->pacman->getX();
    size_t y = this->pacman->getY();

    this->cycleState();

    this->blinky->move(x, y);
    this->pinky->move(x, y);
    this->inky->move(x, y, this->blinky->getLocation());
    this->clyde->move(x, y);
}

void Pacman::GhostManager::draw()
{
    for (auto ghost: this->_ghosts) {
        ghost->draw();
    }
}

bool Pacman::GhostManager::checkCollision()
{
    size_t x = this->pacman->getX();
    size_t y = this->pacman->getY();

    for (auto ghost: this->_ghosts) {
        std::pair<size_t, size_t> loc = ghost->getLocation();
        if (loc.first == x && loc.second == y) {
            if (this->pacman->getState() == Player::State::SUPER) {
                *this->score += 20;
                ghost->setState(GhostState::DEFEATED);
            } else
                return true;
        }
    }
    return false;
}

void Pacman::GhostManager::cycleState()
{
    //    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    for (auto ghost: this->_ghosts) {
        ghost->setActive();
        if (this->pacman->getState() == Player::State::SUPER && ghost->getVulnerable()) {
            ghost->setState(GhostState::HUNTED);
        } else if (this->pacman->getState() == Player::State::NORMAL && ghost->getState() == GhostState::HUNTED) {
            ghost->setState(GhostState::HUNTING);
        }
    }
}

void Pacman::GhostManager::makeVulnerable()
{
    for (auto ghost: this->_ghosts) {
        ghost->setVulnerable(true);
    }
}
