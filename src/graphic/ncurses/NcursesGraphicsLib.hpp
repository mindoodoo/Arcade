/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "IGraphicsLib.hpp"
#include <curses.h>

class NcursesGraphicsLib : virtual public IGraphicsLib
{
    public:
        NcursesGraphicsLib();

        ~NcursesGraphicsLib() override;
};
