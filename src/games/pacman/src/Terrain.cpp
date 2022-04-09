/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "Terrain.hpp"

#define RANGE(a) a.begin(), a.end()

Pacman::Terrain::Terrain(IGraphicsLib **gfx)
{

    this->_map = parseMap("./assets/pacman/pacmanMap.csv");

    this->_height = this->_map.size();
    this->_width = this->_map[0].size();

    this->_gfx = gfx;
    this->_walkable.push_back(TERRAIN_FLOOR);
    this->_walkable.push_back(PACGUM);
    this->_walkable.push_back(BASICALLY_COCAINE);
}

bool Pacman::Terrain::validLocation(size_t x, size_t y)
{
    if (y >= this->_map.size() || x >= this->_map[0].size())
        return true;
    const int tile = this->_map[y][x].tile;

    return std::find(RANGE(this->_walkable), tile) != this->_walkable.end();
}

void Pacman::Terrain::draw()
{
    for (size_t y = 0; y < this->_map.size(); y++) {
        for (size_t x = 0; x < this->_map[y].size(); x++) {
            GFX->drawTile(this->_map[y][x].tile, x, y);
        }
    }
}

size_t Pacman::Terrain::getHeight() const
{
    return this->_height;
}

size_t Pacman::Terrain::getWidth() const
{
    return this->_width;
}

map_t Pacman::Terrain::getMap() const
{
    return this->_map;
}

void Pacman::Terrain::setTile(size_t x, size_t y, int tile)
{
    this->_map[y][x].tile = tile;
}

std::pair<size_t, size_t> Pacman::Terrain::randomLocation()
{
    size_t x;
    size_t y;

    do {
        x = random() % (this->_map.size() - 2) + 1;
        y = random() % (this->_map[0].size() - 2) + 1;
    } while (!this->validLocation(x, y));

    return {x, y};
}
