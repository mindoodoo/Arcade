/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "../../../shared/IGameLib.hpp"
#include "GameCore.hpp"
#include "../../../shared/shared.hpp"

extern "C"
{
    IGameLib *make()
    {
        return new Pacman::GameCore();
    }

    int id = GAME_ID;
    char gameName[] = "pacman";
}
