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
    IGameLib *make()
    {
        return new Core();
    }
}
