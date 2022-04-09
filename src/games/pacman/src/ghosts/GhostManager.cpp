/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "GhostManager.hpp"

std::vector<Pacman::BaseGhost *> Pacman::GhostManager::getGhosts()
{
    return this->_ghosts;
}

Pacman::GhostManager::GhostManager(Pacman::Terrain *scene, IGraphicsLib **gfx, Player *pacman)
{
    //    this->_ghosts = std::vector<Pacman::BaseGhost *>(0);

    this->_ghosts.push_back(new BlinkyGhost(scene, gfx, pacman));
    this->_ghosts.push_back(new PinkyGhost(scene, gfx, pacman));
    this->_ghosts.push_back(new InkyGhost(scene, gfx, pacman));
}

Pacman::BaseGhost *Pacman::GhostManager::getGhost(int id)
{

    for (auto ghost: this->_ghosts) {
        if (ghost->getID() == id)
            return ghost;
    }
    return nullptr;
}

void Pacman::GhostManager::move(int x, int y)
{
    auto blinkyLoc = this->getGhost(BLINKY)->getLocation();

    this->getGhost(BLINKY)->move(x, y);
    this->getGhost(PINKY)->move(x, y);
    dynamic_cast<InkyGhost *>(this->getGhost(INKY))->move(x, y, blinkyLoc.second, blinkyLoc.first);
}

void Pacman::GhostManager::draw()
{
    for (auto ghost: this->_ghosts) {
        ghost->draw();
    }
}

bool Pacman::GhostManager::checkCollision(size_t x, size_t y)
{
    for (auto ghost: this->_ghosts) {
        std::pair<size_t, size_t> loc = ghost->getLocation();
        if (loc.first == x && loc.second == y)
            return true;
    }
    return false;
}
