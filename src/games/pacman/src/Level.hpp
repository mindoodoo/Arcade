/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <utility>
#include <string>
#include "../include/PacmanMacros.hpp"
#include "../../ILevel.hpp"
#include "Terrain.hpp"
#include "Player.hpp"
#include "ghosts/BaseGhost.hpp"
#include "ghosts/GhostManager.hpp"
#include "../../BaseGameCore.hpp"

namespace Pacman
{
    class Level : virtual public ILevel
    {
        public:
            Level(IGraphicsLib **gfx, size_t level);

            ~Level() override = default;

            int frame() override;

            void checkItemCollision();

            int getScore() const override;

            void saveScore() const;
        private:
            Player *_pacman;
            Terrain *_scene;
            GhostManager *_ghosts;
            IGraphicsLib **_gfx;
            LEVEL _state;
            gfx_config_t _levelConf;
            int _score;
            int cocainePillsCount;
    };
}
