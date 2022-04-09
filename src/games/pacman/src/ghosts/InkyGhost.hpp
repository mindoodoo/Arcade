/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "BaseGhost.hpp"

namespace Pacman
{
    class InkyGhost : virtual public BaseGhost
    {
        public:
            InkyGhost(Pacman::Terrain *scene, IGraphicsLib **gfx, Player *pacman, int *score);

            ~InkyGhost() = default;

            void move(size_t x, size_t y, coordinates_t blinkyLoc);

            bool setActive() override;

            int *_score;
    };
}
