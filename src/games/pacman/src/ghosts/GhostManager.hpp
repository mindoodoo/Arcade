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
#include "ClydeGhost.hpp"

namespace Pacman
{
    class GhostManager
    {

        public:
            GhostManager(Terrain *_scene, IGraphicsLib **_gfx, Player *pacman, int *score);

            Pacman::BaseGhost *getGhost(int id);

            void move();

            void draw();

            bool checkCollision();

            void cycleState();

            void makeVulnerable();

        private:
            BlinkyGhost *blinky;
            PinkyGhost *pinky;
            InkyGhost *inky;
            ClydeGhost *clyde;

            GhostState globalState;

            std::vector<BaseGhost *> _ghosts;

            int *score;
            Player *pacman;
            Terrain *_scene;
    };
}
