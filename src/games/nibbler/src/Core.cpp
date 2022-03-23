/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "Core.hpp"
#include "../include/NibblerMacros.hpp"

Core::Core()
    : GenericCore()
{
    this->_highScore = 0;  // TODO: Read from file where we save scores
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

void Core::startGame()
{
    this->_game = new GameManager(this->_gfx);
}
