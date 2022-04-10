/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "Player.hpp"
#include "../../../shared/IGraphicsLib.hpp"
#include "../../ILevel.hpp"
#include "GameCore.hpp"
#include <utility>
#include <fstream>
#include <iostream>
#include <chrono>

namespace Nibbler
{
    class Level : public virtual ILevel
    {
        public:
            explicit Level(IGraphicsLib **gfx, size_t level);

            ~Level();

            int frame() override;

            void draw();

            void checkItemCollision();

            void generateItems(int item, size_t amount);

            bool isTileEmpty(int x, int y);

            std::pair<int, int> randomLocation();

            int getScore() const override;

            std::pair<int, int> circleScan(int r, int x, int y);

        private:
            Player *_nibbler;
            Terrain *_scene;
            std::vector<Item *> _items;
            size_t _gameHeight;
            size_t _gameWidth;
            IGraphicsLib **_gfx;
            int _score;
            gfx_config_t _levelConf;
            int _state = 0;
    };
}
