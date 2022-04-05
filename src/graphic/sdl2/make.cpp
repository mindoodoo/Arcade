/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** make
*/

#include "IGraphicsLib.hpp"
#include "Sdl2GraphicsLib.hpp"
#include "shared.hpp"

extern "C"
{
    IGraphicsLib *make()
    {
        return new Sdl2GraphicsLib();
    }

    int id = GFX_iD;
    char name[] = NAME;
}
