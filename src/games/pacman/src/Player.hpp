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

        public:
            enum State
            {
                NORMAL = 0,
                SUPER = 1,
                DEAD = 2
            };

            Player(size_t start_x, size_t start_y, Terrain *scene, IGraphicsLib **gfx);

            ~Player() = default;

            void move();

            void turn(char xOffset, char yOffset);

            void draw();

            size_t getX() const;

            size_t getY() const;

            std::pair<char, char> getDirection();

            State getState() const;

            void setState(State state);

        private:
            size_t _x;
            size_t _y;

            Terrain *_scene;
            IGraphicsLib **_gfx;

            State _state;

            char _xOffset;
            char _yOffset;

            std::chrono::time_point<std::chrono::system_clock> _playerMovementTime;

            std::chrono::time_point<std::chrono::system_clock> _druggedTimer;

            int druggedDuration_s;
    };
}
