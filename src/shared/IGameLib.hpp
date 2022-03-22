/*
** EPITECH PROJECT, 2022
** IGameLib.hpp
** File description:
** .
*/

#pragma once

#include "IGraphicsLib.hpp"

class IGameLib {
    public:
        ~IGameLib() = default;

        virtual void frame() = 0;

        virtual void setGfx(IGraphicsLib **_gfx) = 0;

    protected:
        IGraphicsLib **_gfx;
};
