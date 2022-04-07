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
    this->_xOffset = 0;
    this->_yOffset = -1;
    this->_playerMovementTime = std::chrono::system_clock::now();
}

void Pacman::Player::draw()
{
    GFX->drawTile(PACMAN_HEAD, this->_x, this->_y);
}

void Pacman::Player::move()
{
    if (!this->_scene->validLocation(this->_x + this->_xOffset, this->_y + this->_yOffset))
        return;

    auto now = std::chrono::system_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_playerMovementTime).count() >= 200) {
        this->_playerMovementTime = now;

        int overflowCheckX = this->_x + this->_xOffset;
        int overflowCheckY = this->_y + this->_yOffset;

        if (overflowCheckX < 0)
            this->_x = this->_scene->getWidth() - 1;
        else if (overflowCheckX >= this->_scene->getWidth())
            this->_x = 0;
        else
            this->_x += this->_xOffset;

        if (overflowCheckY < 0)
            this->_y = this->_scene->getHeight() - 1;
        else if (overflowCheckY >= this->_scene->getHeight())
            this->_y = 0;
        else
            this->_y += this->_yOffset;
    }
}

size_t Pacman::Player::getX() const
{
    return this->_x;
}

size_t Pacman::Player::getY() const
{
    return this->_y;
}

void Pacman::Player::turn(char xOffset, char yOffset)
{
    this->_yOffset = yOffset;
    this->_xOffset = xOffset;
}
