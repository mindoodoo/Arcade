/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <vector>
#include "../../../shared/IGraphicsLib.hpp"
#include <stddef.h>

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

        private:
            std::vector<std::vector<char>> _map;

            std::vector<char> _walkable;

            IGraphicsLib **_gfx;

            size_t _height;
            size_t _width;
    };
}
