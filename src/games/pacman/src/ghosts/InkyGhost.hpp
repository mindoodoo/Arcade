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

            ~InkyGhost();

            void move(size_t x, size_t y, size_t blinkyX, size_t blinkyY);

            bool setActive() override;

            int *_score;
    };
}
