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
        Core();

        void frame() override;

        void showMenu();

        void showGameOver();

        void setHighScore(int highScore);

        void setGfx(IGraphicsLib **gfx) override;

    private:
        int _state;

        GameManager *_game;

        int _level;

        int _highScore;

        IGraphicsLib **_gfx;
};
