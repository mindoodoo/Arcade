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

#define MENU 1
#define IN_GAME 2
#define GAME_OVER 3

class Core : virtual public IGameLib
{
    public:
        explicit Core(IGraphicsLib **gfx);

        int frame() override;

        void showMenu();

        void showGameOver();

        void setHighScore(int highScore);

        void setGfx(IGraphicsLib **gfx) override;

    private:
        int _state;

        int _level;

        int _highScore;

        GameManager *_game;

        IGraphicsLib **_gfx;
};
