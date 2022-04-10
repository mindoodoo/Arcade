/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "Fruit.hpp"
#include "Player.hpp"

Nibbler::Fruit::Fruit(int x, int y, IGraphicsLib **gfx)
    : Item(x, y, ITEM_FRUIT1, gfx)
{
}

void Nibbler::Fruit::effect(Player *nibbler, int *score)
{
    nibbler->appendSegment();
    *score = *score + 1;
}
