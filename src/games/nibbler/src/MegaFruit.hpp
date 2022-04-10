/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "Item.hpp"

namespace Nibbler
{
    class Player;

    class MegaFruit : virtual public Item
    {
        public:
            MegaFruit(int x, int y, IGraphicsLib **gfx);

            void effect(Player *nibbler, int *score) override;
    };
}
