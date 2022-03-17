/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <iostream>
#include "SfmlGraphicsLib.hpp"

void SfmlGraphicsLib::hello()
{
    std::cout << "Hello" << std::endl;
}

IGraphicsLib *entry()
{
    return new SfmlGraphicsLib();
}

struct export_vtable {
    IGraphicsLib *(*entry)();
};

struct export_vtable exports = { entry };
