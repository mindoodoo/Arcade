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

namespace Pacman {
    class Level : virtual public ILevel
    {
        public:
            Level();

            ~Level() = default;

            int frame() override;

            void draw();

            void checkItemCollision();

            void generateItems(int item, size_t amount);

            bool isTileEmpty(int x, int y);

            std::pair<int, int> randomLocation();

            int getScore() const override;

        private:
            //        Nibbler *_nibbler;
            //        Terrain *_scene;
            //        std::vector<Item *> _items;
            size_t _gameHeight;
            size_t _gameWidth;
            //        IGraphicsLib **_gfx;
            int _score;
    };
}
