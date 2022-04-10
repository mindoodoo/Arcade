/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "../shared/IGameLib.hpp"
#include "ILevel.hpp"

#define GS_MENU 1
#define GS_IN_GAME 2
#define GS_GAME_OVER 3

enum LEVEL
{
    RUNNING = 0,
    VICTORY = 1,
    DEFEAT = 2,
};

class BaseGameCore : public virtual IGameLib
{
    public:
        BaseGameCore();

        ~BaseGameCore() override = default;

        int frame() override;

        void setHighScore(int highScore);

        void setGfx(IGraphicsLib **gfx) override;

        virtual void startGame() = 0;

        virtual void showMenu() = 0;

        virtual void showGameOver() = 0;

        gfx_config_t getConfig() override = 0;

    protected:
        int _highScore;

        int _state;

        ILevel *_game;

        IGraphicsLib **_gfx;

        size_t _level;
        size_t _maxLevels;
};
