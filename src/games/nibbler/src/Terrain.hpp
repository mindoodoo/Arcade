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
#include <stddef.h>
#include "Fruit.hpp"
#include "../../../shared/IGraphicsLib.hpp"
#include "../../../shared/shared.hpp"

typedef struct {
    int tile;
    int orientation;
} gfx_tile_t;

namespace Nibbler
{
    class Terrain
    {
        public:

            /**
             * @param tilemapPath
             * @param gfx
             */
            Terrain(std::string tilemapPath, IGraphicsLib **gfx);

            ~Terrain() = default;

            bool validLocation(size_t x, size_t y);

            void draw();

        private:
            std::vector<std::vector<gfx_tile_t>> _map;

            std::vector<int> _walkable;

            IGraphicsLib **_gfx;
    };
}
