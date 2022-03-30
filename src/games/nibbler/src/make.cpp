/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "../../../shared/IGameLib.hpp"
#include "../../../shared/shared.hpp"
#include "GameCore.hpp"
#include "../include/NibblerMacros.hpp"

extern "C"
{
    IGameLib *make()
    {
        return new Nibbler::GameCore();
    }

    int id = GAME_ID;
    char gameName[] = "nibbler";
}
