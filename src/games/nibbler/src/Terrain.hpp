/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <cstddef>
#include <utility>
#include "Fruit.hpp"
#include "../../../shared/IGraphicsLib.hpp"
#include "../../../shared/shared.hpp"

namespace Nibbler
{
    class Terrain
    {
        public:

            /**
             * @param tilemapPath
             * @param gfx
             */
            Terrain(const std::string& tilemapPath, IGraphicsLib **gfx);

            ~Terrain() = default;

            // get dimensions of parsed map
            std::pair<int, int> getMapDimensions() const;

            bool validLocation(size_t x, size_t y);

            void draw();

        private:
            std::vector<std::vector<gfx_tile_t>> _map;

            std::vector<int> _walkable;

            IGraphicsLib **_gfx;
    };
}
