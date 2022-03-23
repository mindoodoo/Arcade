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

namespace Nibbler
{
    class Level : public virtual ILevel
    {
        public:
            explicit Level(IGraphicsLib **gfx);

            ~Level() = default;

            int frame() override;

            void draw();

            void checkItemCollision();

            void generateItems(int item, size_t amount);

            bool isTileEmpty(int x, int y);

            std::pair<int, int> randomLocation();

            int getScore() const override;

        private:
            Player *_nibbler;
            Terrain *_scene;
            std::vector<Item *> _items;
            size_t _gameHeight;
            size_t _gameWidth;
            IGraphicsLib **_gfx;
            int _score;
    };
}
