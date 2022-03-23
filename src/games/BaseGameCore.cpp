/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "GenericCore.hpp"

GenericCore::GenericCore()
{
    this->_highScore = 0;
    this->_state = GS_MENU;
    this->_game = nullptr;
    this->_gfx = nullptr;
}

int GenericCore::frame()
{
    if (this->_state == GS_IN_GAME) {
        if (!this->_game)
            this->startGame();
        GFX->drawText("SCORE: " + std::to_string(this->_game->getScore()), 60, 0);
        GFX->drawText("HIGHSCORE: " + std::to_string(this->_highScore), 60, 1);
        if (this->_game->frame() == GS_GAME_OVER) {
            this->setHighScore(this->_game->getScore());
            this->_state = GS_GAME_OVER;
            this->_game = nullptr;
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

void GenericCore::setHighScore(int highScore)
{
    this->_highScore = highScore;
}

void GenericCore::setGfx(IGraphicsLib **gfx)
{
    this->_gfx = gfx;
}
