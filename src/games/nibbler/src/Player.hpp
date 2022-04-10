/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <deque>
#include <stack>
#include <cstddef>
#include <stdlib.h>
#include "Terrain.hpp"

namespace Nibbler
{
    typedef struct
    {
        int x;
        int y;
    } segment_t;

    class Player
    {
        public:
            Player(int nibbler_start_x, int nibbler_start_y, Terrain *scene, IGraphicsLib **gfx);

            ~Player() = default;

            void appendSegment();

            void popSegment();

            void turn(int xOffset, int yOffset);

            int moveForward();

            segment_t head();

            segment_t tail();

            int getTileOrientation(int bodyIndex) const;

            int getCornerOrientation(int bodyIndex) const;

            void draw();

            bool nibblerCollision(int x, int y);

            size_t length();

        private:
            std::deque<segment_t> _body;

            segment_t _pastTile{};

            Terrain *_scene;

            int _xMovement = -1;

            int _yMovement = 0;

            IGraphicsLib **_gfx;
    };
}
