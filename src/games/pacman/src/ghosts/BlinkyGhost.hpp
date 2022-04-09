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
    class BlinkyGhost : virtual public BaseGhost
    {
        public:
            BlinkyGhost(Terrain *scene, IGraphicsLib **gfx, Player *pacman);

            ~BlinkyGhost() = default;

            void move(size_t x, size_t y) override;

    };
}
