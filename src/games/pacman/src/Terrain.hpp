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
            explicit Terrain(IGraphicsLib **gfx);

            ~Terrain() = default;

            bool validLocation(size_t x, size_t y);

            void draw();

            size_t getHeight() const;

            size_t getWidth() const;

            map_t getMap() const;
        private:
            map_t _map;

            std::vector<char> _walkable;

            IGraphicsLib **_gfx;

            size_t _height;

            size_t _width;
    };
}
