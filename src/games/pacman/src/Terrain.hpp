/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <vector>
#include "Fruit.hpp"
#include "../../../shared/IGraphicsLib.hpp"
#include <stddef.h>

namespace Nibbler
{
    class Terrain
    {
        public:

            /**
             * @param height height in tiles
             * @param width  width in tiles
             * @param gfx
             */
            Terrain(size_t height, size_t width, IGraphicsLib **gfx, const std::string &map_path);

            ~Terrain() = default;

            bool validLocation(size_t x, size_t y);

            void draw();

        private:
            std::vector<std::vector<char>> _map;

            std::vector<char> _walkable;

            IGraphicsLib **_gfx;
    };
}
