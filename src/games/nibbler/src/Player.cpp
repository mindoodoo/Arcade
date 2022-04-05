/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <iostream>
#include <ncurses.h>
#include "Player.hpp"
#include "../include/NibblerMacros.hpp"

Nibbler::Player::Player(int nibbler_start_x, int nibbler_start_y, Terrain *scene, IGraphicsLib **gfx)
{
    this->_scene = scene;
    this->_body.push_back({.x = nibbler_start_x, .y = nibbler_start_y++});
    this->_body.push_back({.x = nibbler_start_x, .y = nibbler_start_y++});
    this->_body.push_back({.x = nibbler_start_x, .y = nibbler_start_y++});
    this->_body.push_back({.x = nibbler_start_x, .y = nibbler_start_y});
    this->_xMovement = 0;
    this->_yMovement = -1;
    this->_gfx = gfx;
}

void Nibbler::Player::appendSegment()
{
    this->_body.push_back({.x = this->_pastTile.x, .y = this->_pastTile.y});
}

void Nibbler::Player::turn(int xOffset, int yOffset)
{
    if (!(xOffset == 0 || yOffset == 0)) {
        std::cout << "Vertical movements not allowed" << std::endl;
    }

    if (this->head().x + xOffset == this->_body[1].x && this->head().y + yOffset == this->_body[1].y)
        return;

    this->_xMovement = xOffset;
    this->_yMovement = yOffset;
}

int Nibbler::Player::moveForward()
{
    const int nextX = this->head().x + this->_xMovement;
    const int nextY = this->head().y + this->_yMovement;

    if (!this->_scene->validLocation(nextX, nextY))
        return false;
    if (this->nibblerCollision(nextX, nextY))
        return false;

    this->_pastTile = {this->tail().x, this->tail().y};

    this->_body.push_front({this->head().x + this->_xMovement, this->head().y + this->_yMovement});

    this->_body.pop_back();

    return true;
}

Nibbler::segment_t Nibbler::Player::head()
{
    return this->_body.front();
}

Nibbler::segment_t Nibbler::Player::tail()
{
    return this->_body.back();
}

int Nibbler::Player::getTileOrientation(int bodyIndex) const
{
    // Head (first tile) orientation
    if (bodyIndex == 0) {
        if (this->_xMovement != 0)
            return (this->_xMovement == -1 ? ORIENT_RIGHT : ORIENT_LEFT);
        if (this->_yMovement != 0)
            return (this->_yMovement == -1 ? ORIENT_BOTTOM : ORIENT_TOP);
    }
    
    // Previous tile has different Y
    switch(this->_body[bodyIndex - 1].y - this->_body[bodyIndex].y) {
        case -1:
            return ORIENT_TOP;
        case 1:
            return ORIENT_BOTTOM;
    }

    // Previous tile has different X
    switch(this->_body[bodyIndex - 1].x - this->_body[bodyIndex].x) {
        case -1:
            return ORIENT_LEFT;
        case 1:
            return ORIENT_RIGHT;
    }
    return ORIENT_TOP;
}

int getTurnDirection(Nibbler::segment_t previous, Nibbler::segment_t current, Nibbler::segment_t next)
{
    // Left is 0 and right is 1

    // If going horizontally before turn
    if (previous.x == current.x) {
        if (next.y > current.y) {
            std::cout << "OUIIIIIIIIIIIIIIIIIIIIIIIIII\n";
            return 1;
        }
        else
            return 0;
    } else { // If going vertically before turn
        if (next.x > current.x) {
            std::cout << "OUIIIIIIIIIIIIIIIIIIIIIIIIII\n";
            return 1;
        }
        else
            return 0;
    }
    return 1;
}

int Nibbler::Player::getCornerOrientation(int bodyIndex) const
{
    segment_t previous = this->_body[bodyIndex - 1]; // Closest to head
    segment_t current = this->_body[bodyIndex]; // Actual corner piece
    segment_t next = this->_body[bodyIndex + 1]; // Closest to tail
    int turnDirection = getTurnDirection(previous, current, next);

    if (turnDirection == 0) {
        if (previous.x < next.x) {
            std::cout << "TOP\n";
            if (previous.y > next.y)
                return (previous.x == current.x ? ORIENT_LEFT : ORIENT_BOTTOM);
            else
                return (previous.x == current.x ? ORIENT_RIGHT : ORIENT_TOP);
        } else { // Bottom corners
            std::cout << "BOTTOM\n";
            if (previous.y < next.y)
                return (previous.x == current.x ? ORIENT_RIGHT : ORIENT_TOP);
            else
                return (previous.x == current.x ? ORIENT_LEFT : ORIENT_BOTTOM);
        }
    }

    // Top corners
    return ORIENT_TOP;
}

void Nibbler::Player::draw()
{
    int tile = NIBBLER_HEAD;
    int orientation;

    for (int i = 0; i < this->_body.size(); i++) {
        // Get correct tile
        if (i == 0)
            tile = NIBBLER_HEAD;
        else if (i == this->_body.size() - 1)
            tile = NIBBLER_TAIL;
        else {
            // Condition to identify corner pieces (works)
            if (this->_body[i - 1].x - this->_body[i + 1].x != 0 &&
            this->_body[i - 1].y - this->_body[i + 1].y != 0)
                tile = NIBBLER_CORNER;
            else
                tile = NIBBLER_BODY1; // This omits alternating tiles
        }

        // Get orientation
        if (tile == NIBBLER_CORNER)
            orientation = this->getCornerOrientation(i);
        else
            orientation = this->getTileOrientation(i);

        // Draw tile
        GFX->drawTile(tile, this->_body[i].x, this->_body[i].y, orientation);
    }
}

bool Nibbler::Player::nibblerCollision(int x, int y)
{
    for (const auto &segment: this->_body) {
        if (segment.x == x && segment.y == y)
            return true;
    }
    return false;
}

size_t Nibbler::Player::length()
{
    return this->_body.size();
}
