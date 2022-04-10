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

            gfx_config_t getConfig() override;
        private:
            gfx_config_t _levelConf;
            std::vector<std::vector<gfx_tile_t>> _menuMap;
    };

}
