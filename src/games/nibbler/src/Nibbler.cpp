/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <iostream>
#include <ncurses.h>
#include "Nibbler.hpp"
#include "../include/NibblerMacros.hpp"

Nibbler::Nibbler(int nibbler_start_x, int nibbler_start_y, Terrain *scene)
{
    this->_scene = scene;
    this->_body.push_back({.x = nibbler_start_x, .y = nibbler_start_y++});
    this->_body.push_back({.x = nibbler_start_x, .y = nibbler_start_y++});
    this->_body.push_back({.x = nibbler_start_x, .y = nibbler_start_y++});
    this->_body.push_back({.x = nibbler_start_x, .y = nibbler_start_y});
    this->_xMovement = 0;
    this->_yMovement = -1;
}

void Nibbler::appendSegment()
{
    this->_body.push_back({.x = this->_pastTile.x, .y = this->_pastTile.y});
}

void Nibbler::turn(int xOffset, int yOffset)
{
    if (!(xOffset == 0 || yOffset == 0)) {
        std::cout << "Vertical movements not allowed" << std::endl;
    }

    if (this->head().x + xOffset == this->_body[1].x && this->head().y + yOffset == this->_body[1].y)
        return;

    this->_xMovement = xOffset;
    this->_yMovement = yOffset;
}

int Nibbler::moveForward()
{
    const int nextX = this->head().x + this->_xMovement;
    const int nextY = this->head().y + this->_yMovement;

    if (!this->_scene->validLocation(nextX, nextY))
        return true;
    if (this->nibblerCollision(nextX, nextY))
        return false;

    this->_pastTile = {this->tail().x, this->tail().y};

    this->_body.push_front({this->head().x + this->_xMovement, this->head().y + this->_yMovement});

    this->_body.pop_back();

    return true;
}

segment_t Nibbler::head()
{
    return this->_body.front();
}

segment_t Nibbler::tail()
{
    return this->_body.back();
}

void Nibbler::draw()
{
    for (int i = 0; i < this->_body.size(); i++) {
        if (i == 0)
            mockDrawTile(NIBBLER_HEAD, this->_body[i].x, this->_body[i].y);
        else if (i == this->_body.size() - 1)
            mockDrawTile(NIBBLER_TAIL, this->_body[i].x, this->_body[i].y);
        else
            mockDrawTile(NIBBLER_BODY, this->_body[i].x, this->_body[i].y);
    }
}

bool Nibbler::nibblerCollision(int x, int y)
{
    for (const auto &segment: this->_body) {
        if (segment.x == x && segment.y == y)
            return true;
    }
    return false;
}

size_t Nibbler::length()
{
    return this->_body.size();
}
