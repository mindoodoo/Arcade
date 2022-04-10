/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <iostream>
#include "BaseGameCore.hpp"

BaseGameCore::BaseGameCore()
{
    this->_highScore = 0;
    this->_state = GS_MENU;
    this->_game = nullptr;
    this->_gfx = nullptr;
    this->_level = 0;
    this->_maxLevels = 0;
}

int BaseGameCore::frame()
{
    if (this->_state == GS_IN_GAME) {
        if (!this->_game)
            this->startGame();

        GFX->drawText("SCORE: " + std::to_string(this->_game->getScore()), 60, 0);
        GFX->drawText("HIGHSCORE: " + std::to_string(this->_highScore), 60, 1);

        int levelState = this->_game->frame();
        if (levelState == LEVEL::DEFEAT) {
            this->setHighScore(this->_game->getScore());
            this->_state = GS_GAME_OVER;
            delete this->_game;
            this->_game = nullptr;
            GFX->flush();
        } else if (levelState == LEVEL::VICTORY) {
            this->setHighScore(this->_game->getScore());
            this->_state = GS_MENU;
            delete this->_game;
            this->_game = nullptr;
            if (this->_level < this->_maxLevels)
                this->_level++;
            GFX->flush();
        }
    } else {
        if (this->_state == GS_MENU)
            this->showMenu();

        else if (this->_state == GS_GAME_OVER)
            this->showGameOver();

        auto inputs = GFX->getInput();

        if (!inputs.empty()) {
            char c = inputs.back();
            GFX->popInput();

            switch (c) {
                case 's':
                    this->startGame();
                    this->_state = GS_IN_GAME;
                    GFX->flush();
                    break;
                case 'q':
                    return QUIT_SIGNAL;
            }
        }
    }
    return SUCCESS_SIGNAL;
}

void BaseGameCore::setHighScore(int highScore)
{
    this->_highScore = highScore;
}

void BaseGameCore::setGfx(IGraphicsLib **gfx)
{
    this->_gfx = gfx;
}
