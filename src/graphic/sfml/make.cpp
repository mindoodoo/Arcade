/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "IGraphicsLib.hpp"
#include "SfmlGraphicsLib.hpp"
#include "shared.hpp"

extern "C"
{
    IGraphicsLib *make()
    {
        return new SfmlGraphicsLib();
    }

    int id = GFX_iD;
    char name[] = NAME;
}
