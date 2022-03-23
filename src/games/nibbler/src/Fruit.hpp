/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <utility>
#include "Item.hpp"

namespace Nibbler
{
    class Player;

    class Fruit : virtual public Item
    {
        public:
            Fruit(int x, int y, IGraphicsLib **gfx);

            void effect(Player *nibbler) override;
    };
}
