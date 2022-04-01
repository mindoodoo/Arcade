/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "../../../shared/IGraphicsLib.hpp"
#include "Terrain.hpp"

namespace Pacman
{
    class Player
    {
            enum State
            {
                NORMAL = 0,
                SUPER = 1,
                DEAD = 2
            };

        public:
            Player(size_t start_x, size_t start_y, Terrain *scene, IGraphicsLib **gfx);

            ~Player() = default;

            void move(size_t xOffset, size_t yOffset);

            void draw();
        private:
            size_t _x;
            size_t _y;

            Terrain *_scene;
            IGraphicsLib **_gfx;

            State _state;
    };
}
