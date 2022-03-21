/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "GameManager.hpp"

#define MENU 1
#define IN_GAME 2
#define GAME_OVER 3


class Core
{
    public:
        Core();

        void frame();

        void showMenu();

        void showGameOver();

        void setHighScore(int highScore);

    private:
        int _state;

        GameManager *_game;

        int _level;

        int _highScore;
};
