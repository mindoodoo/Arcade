/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/


#include "Item.hpp"
#include "../include/NibblerMacros.hpp"

Item::Item(int x, int y, char c, IGraphicsLib **gfx)
{
    this->_x = x;
    this->_y = y;
    this->_symbol = c;
    this->_gfx = gfx;
}

std::pair<int, int> Item::getLocation()
{
    return {this->_x, this->_y};
}

void Item::draw()
{
    (*this->_gfx)->drawTile(this->_symbol, this->_x, this->_y);
}

bool Item::itemCollision(int x, int y) const
{
    return x == this->_x && y == this->_y;
}

void Item::relocate(int x, int y)
{
    this->_x = x;
    this->_y = y;
}
