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
    this->druggedDuration_s = 10;
}

void Pacman::Player::draw()
{
    GFX->drawTile(PACMAN_HEAD, this->_x, this->_y);
}

void Pacman::Player::move()
{
    auto now = std::chrono::system_clock::now();

    if (std::chrono::duration_cast<std::chrono::seconds>(now - this->_druggedTimer).count() >= 10)
        this->setState(State::NORMAL);

    if (!this->_scene->validLocation(this->_x + this->_xOffset, this->_y + this->_yOffset))
        return;

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_playerMovementTime).count() >= 200) {
        this->_playerMovementTime = now;

        int overflowCheckX = (int) this->_x + this->_xOffset;
        int overflowCheckY = (int) this->_y + this->_yOffset;

        if (overflowCheckX < 0)
            this->_x = this->_scene->getWidth() - 1;
        else if (overflowCheckX >= (int)this->_scene->getWidth())
            this->_x = 0;
        else
            this->_x += this->_xOffset;

        if (overflowCheckY < 0)
            this->_y = this->_scene->getHeight() - 1;
        else if (overflowCheckY >= (int)this->_scene->getHeight())
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
    // Check direction is valid before turning so that pacman does not have the ability to stop
    if (!this->_scene->validLocation(this->_x + xOffset, this->_y + yOffset))
        return;

    this->_yOffset = yOffset;
    this->_xOffset = xOffset;
}

std::pair<char, char> Pacman::Player::getDirection()
{
    return {this->_xOffset, this->_yOffset};
}

Pacman::Player::State Pacman::Player::getState() const
{
    return this->_state;
}

void Pacman::Player::setState(Pacman::Player::State state)
{
    if (state == State::SUPER)
        this->_druggedTimer = std::chrono::system_clock::now();
    this->_state = state;
}
