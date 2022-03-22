/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <ncurses.h>
#include "Core.hpp"
#include "../include/NibblerMacros.hpp"

Core::Core()
{
    this->_state = MENU;
    this->_game = nullptr;
    this->_level = 0;
    mockInitGfxLib();
}

void Core::frame()
{

    if (this->_state == IN_GAME) {
        if (!this->_game)
            this->_game = new GameManager(this->_level);
        mockShowText("SCORE: " + std::to_string(this->_game->getScore()), 60, 0);
        mockShowText("HIGHSCORE: " + std::to_string(this->_highScore), 60, 1);
        if (this->_game->frame() == GAME_OVER) {
            this->setHighScore(this->_game->getScore());
            this->_state = GAME_OVER;
            this->_game = nullptr;
            this->_level++;
            clear();
        }
    } else {
        if (this->_state == MENU)
            this->showMenu();
        else if (this->_state == GAME_OVER)
            this->showGameOver();
        switch (getch()) {
            case 's':
                clear();
                this->_game = new GameManager(this->_level);
                this->_state = IN_GAME;
        }
    }
}

void Core::showMenu()
{
    mockShowText("IN MENU, PRESS S TO PLAY", 0, 0);

    mockShowText("HIGHSCORE: " + std::to_string(this->_highScore), 0, 1);
}

void Core::showGameOver()
{
    mockShowText("YOU LOST, PRESS S TO TRY AGAIN", 0, 0);

    mockShowText("HIGHSCORE: " + std::to_string(this->_highScore), 0, 1);
}

void Core::setHighScore(int highScore)
{
    if (highScore > this->_highScore) {
        this->_highScore = highScore;
    }
}

void Core::setGfx(IGraphicsLib **gfx)
{
    this->_gfx = gfx;
}
