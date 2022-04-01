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

Nibbler::Terrain::Terrain(size_t height, size_t width, IGraphicsLib **gfx, const std::string &map_path)
{
    this->_map = std::vector<std::vector<char>>(height);

    for (size_t i = 0; i < height; i++) {
        this->_map[i] = std::vector<char>(width);
        for (size_t j = 0; j < width; j++) {
            if (i == 0 || i == (height - 1) || j == 0 || (j == width - 1))
                this->_map[i][j] = TERRAIN_WALL;
            else
                this->_map[i][j] = TERRAIN_FLOOR;
        }
    }

    this->_gfx = gfx;
    this->_walkable.push_back(TERRAIN_FLOOR);
}

bool Nibbler::Terrain::validLocation(size_t x, size_t y)
{
    if (y >= this->_map.size() || x >= this->_map[0].size())
        return false;
    const char tile = this->_map[y][x];

    return std::find(RANGE(this->_walkable), tile) != this->_walkable.end();
}

void Nibbler::Terrain::draw()
{
    for (size_t x = 0; x < this->_map.size(); x++) {
        for (size_t y = 0; y < this->_map[x].size(); y++) {
            GFX->drawTile(this->_map[x][y], x, y);
        }
    }
}
