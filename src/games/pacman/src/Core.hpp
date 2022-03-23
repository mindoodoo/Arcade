/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "../../../shared/IGameLib.hpp"

class Core
{
    public:
        Core();

        int frame();

    private:
        int _state;
        void *_game;
        int _level;
        int _highScore;

        void showMenu();

        void showGameOver();

        void setHighScore(int highScore);
};
