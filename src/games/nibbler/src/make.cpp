/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "../../../shared/IGameLib.hpp"
#include "Core.hpp"

extern "C"
{
IGameLib *make(IGraphicsLib **gfx)
{
    return new Core(gfx);
}
}
