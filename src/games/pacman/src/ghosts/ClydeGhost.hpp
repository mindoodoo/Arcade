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
    class ClydeGhost : virtual public BaseGhost
    {
        public:
            ClydeGhost(Terrain *scene, IGraphicsLib **gfx, Player *pacman);

            ~ClydeGhost() = default;

            void move(size_t x, size_t y) override;
    };
}
