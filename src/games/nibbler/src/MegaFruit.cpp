/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "MegaFruit.hpp"
#include "Player.hpp"

Nibbler::MegaFruit::MegaFruit(int x, int y, IGraphicsLib **gfx)
    : Item(x, y, ITEM_FRUIT2, gfx)
{
}

void Nibbler::MegaFruit::effect(Nibbler::Player *nibbler, int *score)
{
    nibbler->popSegment();
    *score = *score + 2;
}
