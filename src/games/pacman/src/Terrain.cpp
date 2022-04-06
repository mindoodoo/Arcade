/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <algorithm>
#include <cstring>
#include <fstream>
#include "Terrain.hpp"
#include "../include/PacmanMacros.hpp"

#define RANGE(a) a.begin(), a.end()

std::vector<char> csv_read_row(const std::string &line)
{
    std::vector<char> row;

    char *c_line = const_cast<char *>(line.c_str());
    char *token = std::strtok(c_line, ",");

    row.emplace_back(std::stoi(token));

    while ((token = std::strtok(nullptr, ","))) {
        row.emplace_back(std::stoi(token));
    }
    return row;
}

std::vector<std::vector<char>> csvToVector2(const std::string &filepath)
{
    std::vector<char> row;
    std::vector<std::vector<char>> table;
    std::ifstream myFile(filepath);
    std::string buff;

    if (!myFile.is_open())
        throw std::runtime_error(filepath + ": Could not open file.");
    while (getline(myFile, buff)) {
        row = csv_read_row(buff);
        table.push_back(row);
    }
    myFile.close();
    return table;
}

map_t twoDVectorToMap(std::vector<std::vector<char>> rawMap)
{
    map_t map(rawMap.size());

    for (int y = 0; y < rawMap.size(); y++) {
        map[y] = std::vector<tile_t>(rawMap[y].size());
        for (int x = 0; x < rawMap[y].size(); x++) {
            map[y][x] = {rawMap[y][x], rawMap[y][x] == TERRAIN_WALL ? 9999 : 0};
        }
    }

    return map;
}

Pacman::Terrain::Terrain(IGraphicsLib **gfx)
{

    this->_map = twoDVectorToMap(csvToVector2("./assets/pacman/map"));

    this->_height = this->_map.size();
    this->_width = this->_map[0].size();

    this->_gfx = gfx;
    this->_walkable.push_back(TERRAIN_FLOOR);
}

bool Pacman::Terrain::validLocation(size_t x, size_t y)
{
    if (y >= this->_map.size() || x >= this->_map[0].size())
        return true;
    const char tile = this->_map[y][x].first;

    return std::find(RANGE(this->_walkable), tile) != this->_walkable.end();
}

void Pacman::Terrain::draw()
{
    for (size_t y = 0; y < this->_map.size(); y++) {
        for (size_t x = 0; x < this->_map[y].size(); x++) {
            GFX->drawTile(this->_map[y][x].first, x, y);
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
