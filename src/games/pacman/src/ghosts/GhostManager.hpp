/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "BaseGhost.hpp"
#include "BlinkyGhost.hpp"
#include "PinkyGhost.hpp"
#include "InkyGhost.hpp"

namespace Pacman
{
    class GhostManager
    {
        public:
            GhostManager(Terrain *_scene, IGraphicsLib **_gfx, Player *pacman);

            std::vector<Pacman::BaseGhost *> getGhosts();

            Pacman::BaseGhost *getGhost(int id);

            void move(int x, int y);

            void draw();

        private:

            std::vector<Pacman::BaseGhost *> _ghosts;
    };
}
