/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <utility>
#include "../../../shared/IGraphicsLib.hpp"

class Nibbler;

class Item
{
    public:
        Item(int x, int y, char c, IGraphicsLib **gfx);

        std::pair<int, int> getLocation();

        void draw();

        bool itemCollision(int x, int y) const;

        virtual void effect(Nibbler *nibbler) = 0;

        void relocate(int x, int y);

    protected:
        int _x;
        int _y;
        char _symbol;
        IGraphicsLib **_gfx;
};
