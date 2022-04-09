/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <vector>
#include <algorithm>
#include <cstring>
#include <cstddef>
#include "../include/PacmanMacros.hpp"
#include "../../../shared/IGraphicsLib.hpp"
#include "../../../shared/shared.hpp"
#include <chrono>
#include <iostream>

/**
 * first = id of the tile
 * second = cost
 */

typedef std::vector<std::vector<gfx_tile_t>> map_t;

namespace Pacman
{
    class Terrain
    {
        public:

            /**
             * @param gfx
             */
            explicit Terrain(const std::string &tileMapPath, IGraphicsLib **gfx);

            ~Terrain() = default;

            bool validLocation(size_t x, size_t y);

            void draw();

            size_t getHeight() const;

            size_t getWidth() const;

            map_t getMap() const;

            void setTile(size_t x, size_t y, int tile);

            std::pair<size_t, size_t> randomLocation();

            int tileCount(int tile);
        private:
            map_t _map;

            std::vector<char> _walkable;

            IGraphicsLib **_gfx;

            size_t _height;

            size_t _width;
    };
}
