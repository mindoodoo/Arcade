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
    this->_x = 10;
    this->_y = 11;
    this->_initialSleepSeconds = 15;
    this->_id = PINKY;
}

void Pacman::PinkyGhost::move(size_t x, size_t y)
{

    std::pair<char, char> dir = this->_pacman->getDirection();
    this->masterMove(x + dir.first * 4, y + dir.second * 4);
}
