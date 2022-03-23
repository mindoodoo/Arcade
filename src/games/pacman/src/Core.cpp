/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "Core.hpp"
#include "../include/PacmanMacros.hpp"

Core::Core()
{
    this->_state = GS_MENU;
    this->_game = nullptr;
    this->_level = 0;
    this->_highScore = 0;  // TODO: Read from file where we save scores
}

int Core::frame()
{
    return QUIT_SIGNAL;
}

void Core::showMenu()
{
    GFX->drawText("IN MENU, PRESS S TO PLAY\n PRESS Q TO QUIT", 0, 0);

    GFX->drawText("HIGHSCORE: " + std::to_string(this->_highScore), 0, 1);
}

void Core::showGameOver()
{
    GFX->drawText("YOU LOST, PRESS S TO TRY AGAIN\n PRESS Q TO QUIT", 0, 0);

    GFX->drawText("HIGHSCORE: " + std::to_string(this->_highScore), 0, 1);
}

void Core::setHighScore(int highScore)
{
    if (highScore > this->_highScore) {
        this->_highScore = highScore;
    }
}
