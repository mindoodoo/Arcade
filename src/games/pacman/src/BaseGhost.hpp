/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "chrono"
#include "Terrain.hpp"
#include "Astar.hpp"
#include "../include/PacmanMacros.hpp"
#include <utility>

namespace Pacman
{
    enum GhostState
    {
        HUNTING = 0,
        HUNTED = 1,
        DEFEATED = 2,
        RECOVERING = 3,
        SLEEPING = 4
    };

    class BaseGhost
    {
        public:
            BaseGhost(Terrain *_scene, IGraphicsLib **_gfx);

            void setState(GhostState state);

            void move(int x, int y);

            void draw();
        protected:
            GhostState _state;

            int stateChangeTimer{};

            int moveTimer{};

            size_t _x;

            size_t _y;

            Terrain *_scene;

            IGraphicsLib **_gfx;
    };
}
