/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <iostream>
#include "Player.hpp"
#include "../include/PacmanMacros.hpp"

Pacman::Player::Player(size_t start_x, size_t start_y, Pacman::Terrain *scene, IGraphicsLib **gfx)
{
    this->_x = start_x;
    this->_y = start_y;
    this->_scene = scene;
    this->_gfx = gfx;
    this->_state = State::NORMAL;
}

void Pacman::Player::draw()
{
    GFX->drawTile(PACMAN_HEAD, this->_x, this->_y);
}

void Pacman::Player::move(size_t xOffset, size_t yOffset)
{
    if (!(xOffset == 0 || yOffset == 0)) {
        std::cout << "Vertical movements not allowed" << std::endl;
    }

    if (!this->_scene->validLocation(this->_x + xOffset, this->_y + yOffset))
        return;

    int overflowCheckX = this->_x + xOffset;
    int overflowCheckY = this->_y + yOffset;

    if (overflowCheckX < 0)
        this->_x = this->_scene->getWidth() - 1;
    else if (overflowCheckX >= this->_scene->getWidth())
        this->_x = 0;
    else
        this->_x += xOffset;

    if (overflowCheckY < 0)
        this->_y = this->_scene->getHeight() - 1;
    else if (overflowCheckY >= this->_scene->getHeight())
        this->_y = 0;
    else
        this->_y += yOffset;
}

size_t Pacman::Player::getX() const
{
    return this->_x;
}

size_t Pacman::Player::getY() const
{
    return this->_y;
}
