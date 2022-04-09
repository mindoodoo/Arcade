/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <algorithm>
#include <ncurses.h>
#include "Terrain.hpp"
#include "../include/NibblerMacros.hpp"

#define RANGE(a) a.begin(), a.end()

Nibbler::Terrain::Terrain(const std::string &tileMapPath, IGraphicsLib **gfx)
{
    // Set gfx pointer used for drawing
    this->_gfx = gfx;

    this->_map = parseMap(tileMapPath);

    // Define walkable tiles for collision detection
    this->_walkable.push_back(TERRAIN_FLOOR);
}

bool Nibbler::Terrain::validLocation(size_t x, size_t y)
{
    if (y >= this->_map.size() || x >= this->_map[0].size())
        return false;
    int tile = this->_map[y][x].tile; //

    return std::find(RANGE(this->_walkable), tile) != this->_walkable.end();
}

void Nibbler::Terrain::draw()
{
    for (size_t y = 0; y < this->_map.size(); y++)
        for (size_t x = 0; x < this->_map[y].size(); x++)
            GFX->drawTile(this->_map[y][x].tile, x, y, this->_map[y][x].orientation);
}

std::pair<int, int> Nibbler::Terrain::getMapDimensions() const
{
    return std::make_pair(this->_map[0].size(), this->_map.size());
}
