/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "Level.hpp"
#include "../../../shared/IGraphicsLib.hpp"
#include "../../../shared/IGameLib.hpp"
#include "../../GenericCore.hpp"

namespace Nibbler
{
    class GameCore : virtual public GenericCore
    {
        public:
            GameCore();

            void showMenu() override;

            void showGameOver() override;

            void startGame() override;
    };
}
