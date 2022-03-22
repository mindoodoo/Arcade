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

Terrain::Terrain(size_t height, size_t width, IGraphicsLib **gfx)
{
    this->_map = std::vector<std::vector<char>>(height);

    for (int i = 0; i < height; i++) {
        this->_map[i] = std::vector<char>(width);
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == (height - 1) || j == 0 || (j == width - 1))
                this->_map[i][j] = TERRAIN_WALL;
            else
                this->_map[i][j] = TERRAIN_FLOOR;
        }
    }

    this->_gfx = gfx;
    this->_walkable.push_back(TERRAIN_FLOOR);
}

bool Terrain::validLocation(int x, int y)
{
    if (!((y < (this->_map.size() - 1)) || (x < (this->_map[0].size() - 1))))
        return false;

    const char tile = this->_map[y][x];

    return std::find(RANGE(this->_walkable), tile) != this->_walkable.end();
}

void Terrain::draw()
{
    for (int x = 0; x < this->_map.size(); x++) {
        for (int y = 0; y < this->_map[x].size(); y++) {
            GFX->drawTile(this->_map[x][y], x, y);
        }
    }
}
