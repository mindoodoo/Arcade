/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "../../../shared/IGameLib.hpp"
#include "Level.hpp"
#include "../../BaseGameCore.hpp"

namespace Pacman
{
    class GameCore : virtual public BaseGameCore
    {
        public:
            GameCore();

            void showMenu() override;

            void showGameOver() override;

            void startGame() override;

        private:

            int _level;
    };
}
