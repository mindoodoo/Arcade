/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/


#include <iostream>
#include "BaseGhost.hpp"

void Pacman::BaseGhost::setState(Pacman::GhostState state)
{
    this->_state = state;
    this->stateChangeTimer;
}

void Pacman::BaseGhost::move(int x, int y)
{
    std::deque<coordinates_t> path = calculateAStar({this->_x, this->_y}, {x, y}, this->_scene->getMap());
    std::cout << "move" << std::endl;

    std::cout << path.front().first << " " << path.front().second << "move" << std::endl;

    this->_x = path.front().first;
    this->_y = path.front().second;
}

void Pacman::BaseGhost::draw()
{
    GFX->drawTile(PACMAN_HEAD, this->_x, this->_y);
}

Pacman::BaseGhost::BaseGhost(Pacman::Terrain *scene, IGraphicsLib **gfx)
{
    this->_scene = scene;
    this->_gfx = gfx;
    this->setState(GhostState::SLEEPING);

    this->_x = 2;
    this->_y = 2;

}
