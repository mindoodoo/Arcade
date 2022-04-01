/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "IGraphicsLib.hpp"
#include "NcursesGraphicsLib.hpp"
#include "shared.hpp"

extern "C"
{
    IGraphicsLib *make()
    {
        return new NcursesGraphicsLib();
    }

    int id = GFX_iD;
    char name[] = NAME;
}
