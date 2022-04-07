/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <chrono>
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

            void move();

            void turn(char xOffset, char yOffset);

            void draw();

            size_t getX() const;

            size_t getY() const;
        private:
            size_t _x;
            size_t _y;

            Terrain *_scene;
            IGraphicsLib **_gfx;

            State _state;

            char _xOffset;
            char _yOffset;

            std::chrono::time_point<std::chrono::system_clock> _playerMovementTime;
    };
}
