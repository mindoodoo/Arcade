/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "../shared/IGameLib.hpp"
#include "IGameManager.hpp"

#define GS_MENU 1
#define GS_IN_GAME 2
#define GS_GAME_OVER 3

class GenericCore : public virtual IGameLib
{
    public:
        GenericCore();

        ~GenericCore() = default;

        int frame() override;

        void setHighScore(int highScore);

        void setGfx(IGraphicsLib **gfx) override;

        virtual void startGame() = 0;

        virtual void showMenu() = 0;

        virtual void showGameOver() = 0;
    protected:
        int _highScore;

        int _state;

        IGameManager *_game;

        IGraphicsLib **_gfx;
};
