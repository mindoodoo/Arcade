/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "GameManager.hpp"
#include "../../../shared/IGraphicsLib.hpp"
#include "../../../shared/IGameLib.hpp"
#include "../../GenericCore.hpp"

class Core : virtual public GenericCore
{
    public:
        Core();

        void showMenu() override;

        void showGameOver() override;

        void startGame() override;
};
