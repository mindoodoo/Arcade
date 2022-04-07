/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "GameCore.hpp"

Pacman::GameCore::GameCore()
{
    this->_state = GS_MENU;
    this->_game = nullptr;
    this->_level = 0;
    this->_highScore = 0;  // TODO: Read from file where we save scores
    this->_gfx = nullptr;

    this->_levelConf = {
        "./assets/pacman/asciiTileset.csv",
        "./assets/pacman/NibblerTestTileset.png",
        "./assets/pacman/arial.ttf",
        64,
        64,
        30,
        30
    };
}

void Pacman::GameCore::showMenu()
{
    GFX->drawText("WELCOME TO PACMAN", 0, 0);
    GFX->drawText("IN MENU, PRESS S TO PLAY", 0, 1);
    GFX->drawText("PRESS Q TO QUIT", 0, 2);
    GFX->drawText("HIGHSCORE: " + std::to_string(this->_highScore), 0, 3);
    GFX->drawText("GS: " + std::to_string(this->_state), 0, 4);
}

void Pacman::GameCore::showGameOver()
{
    GFX->drawText("YOU LOST, PRESS S TO TRY AGAIN", 0, 0);
    GFX->drawText("PRESS Q TO QUIT", 0, 1);
    GFX->drawText("HIGHSCORE: " + std::to_string(this->_highScore), 0, 2);
}

void Pacman::GameCore::startGame()
{
    this->_game = new Level(this->_gfx, this->_levelConf);
}

gfx_config_t Pacman::GameCore::getConfig()
{
    return this->_levelConf;
}
