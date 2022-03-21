/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "Fruit.hpp"
#include "Nibbler.hpp"
#include "../include/NibblerMacros.hpp"

Fruit::Fruit(int x, int y)
    : Item(x, y, ITEM_FRUIT)
{
}

void Fruit::effect(Nibbler *nibbler)
{
    nibbler->appendSegment();
}
