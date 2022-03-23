/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "IGraphicsLib.hpp"
#include "NcursesGraphicsLib.hpp"

extern "C"
{
    IGraphicsLib *make()
    {
        return new NcursesGraphicsLib();
    }
}
