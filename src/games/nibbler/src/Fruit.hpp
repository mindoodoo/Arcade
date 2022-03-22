/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <utility>
#include "Item.hpp"

class Nibbler;

class Fruit : virtual public Item
{
    public:
        Fruit(int x, int y, IGraphicsLib **gfx);

        void effect(Nibbler *nibbler) override;
};
