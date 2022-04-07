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
#include "BaseGhost.hpp"

namespace Pacman
{
    class Level : virtual public ILevel
    {
        public:
            Level(IGraphicsLib **gfx, gfx_config_t levelConf);

            ~Level() override = default;

            int frame() override;

            void draw();

            void checkItemCollision();

            void generateItems(int item, size_t amount);

            bool isTileEmpty(int x, int y);

            std::pair<int, int> randomLocation();

            int getScore() const override;

        private:
            Player *_pacman;
            Terrain *_scene;

            BaseGhost *_ghost;
            //        std::vector<Item *> _items;
            //            size_t _gameHeight;
            //            size_t _gameWidth;
            IGraphicsLib **_gfx;
            gfx_config_t _levelConf;
            int _score;

            std::chrono::time_point<std::chrono::system_clock> _ghostMovementTime;
    };
}
