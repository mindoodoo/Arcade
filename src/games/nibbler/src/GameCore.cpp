/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "GameCore.hpp"
#include "../include/NibblerMacros.hpp"

Nibbler::GameCore::GameCore()
    : BaseGameCore()
{
    this->_highScore = 0;  // TODO: Read from file where we save scores

    // Hardcoded for the time being, we can add multiple level parsing in the future
    this->_levelConf = {
        "./assets/nibbler/asciiTileset.csv",
        "./assets/nibbler/NibblerTestTileset.png",
        "", // TODO: These other elements will be implemented later
        64,
        64,
        30,
        30
    };
}

void Nibbler::GameCore::showMenu()
{
    GFX->drawText("WELCOME TO NIBBLER", 0, 0);
    GFX->drawText("IN MENU, PRESS S TO PLAY", 0, 1);
    GFX->drawText("PRESS Q TO QUIT", 0, 2);
    GFX->drawText("HIGHSCORE: " + std::to_string(this->_highScore), 0, 3);
}

void Nibbler::GameCore::showGameOver()
{
    GFX->drawText("YOU LOST, PRESS S TO TRY AGAIN", 0, 0);
    GFX->drawText("PRESS Q TO QUIT", 0, 1);
    GFX->drawText("HIGHSCORE: " + std::to_string(this->_highScore), 0, 2);
}

void Nibbler::GameCore::startGame()
{
    this->_game = new Level(this->_gfx, this->_levelConf);
}
