/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "../../../shared/IGameLib.hpp"
#include "GameCore.hpp"

extern "C"
{
    IGameLib *make()
    {
        return new Nibbler::GameCore();
    }
}
