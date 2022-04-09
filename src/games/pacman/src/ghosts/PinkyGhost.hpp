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
    class PinkyGhost : virtual public BaseGhost
    {
        public:
            PinkyGhost(Terrain *scene, IGraphicsLib **gfx, Player *pacman);

            ~PinkyGhost() = default;

            void move(size_t x, size_t y) override;

    };
}
