/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "../../../shared/IGameLib.hpp"
#include "PacmanLevel.hpp"
#include "../../GenericCore.hpp"

namespace Pacman
{
    class Core : virtual public GenericCore
    {
        public:
            explicit Core(IGraphicsLib **gfx);

            void showMenu() override;

            void showGameOver() override;

            void startGame() override;

        private:

            int _level;
    };
}
