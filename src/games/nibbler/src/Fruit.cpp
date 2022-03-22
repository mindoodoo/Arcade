/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "Fruit.hpp"
#include "Nibbler.hpp"
#include "../include/NibblerMacros.hpp"

Fruit::Fruit(int x, int y, IGraphicsLib **gfx)
    : Item(x, y, ITEM_FRUIT, gfx)
{
}

void Fruit::effect(Nibbler *nibbler)
{
    nibbler->appendSegment();
}
