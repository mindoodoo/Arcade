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
    this->_level = 1;
    this->_highScore = 0;  // TODO: Read from file where we save scores
    this->_gfx = nullptr;

    this->_levelConf = parseGfx(CONFIG_PATH);
    this->_maxLevels = csvToTable(CONFIG_PATH).size();

    this->_menuMap = parseMap(this->_levelConf.mapPath);
    this->_levelConf.windowWidth = this->_menuMap[0].size();
    this->_levelConf.windowHeight = this->_menuMap.size();
}

void Pacman::GameCore::showMenu()
{
    rgb_t textColor = {236,236,14};

    GFX->checkConfig(this->_levelConf);

    // Draw core map
    for (size_t y = 0; y < this->_menuMap.size(); y++)
        for (size_t x = 0; x < this->_menuMap[y].size(); x++)
            GFX->drawTile(this->_menuMap[y][x].tile, x, y);

    GFX->drawText("WELCOME TO PACMAN !", 24, 10, textColor);
    GFX->drawText("Press S to start playing...", 24, 12, textColor);
    GFX->drawText("Press Q to return to main menu...", 24, 13, textColor);
}

void Pacman::GameCore::showGameOver()
{
    GFX->checkConfig(this->_levelConf);
    
    rgb_t textColor = {236,236,14};

    // Draw core map
    for (size_t y = 0; y < this->_menuMap.size(); y++)
        for (size_t x = 0; x < this->_menuMap[y].size(); x++)
            GFX->drawTile(this->_menuMap[y][x].tile, x, y);

    GFX->drawText("Game Over...", 24, 10, textColor);
    GFX->drawText("Press S to play again...", 24, 12, textColor);
    GFX->drawText("Press Q to return to main menu...", 24, 13, textColor);
}

void Pacman::GameCore::startGame()
{
    this->_game = new Level(this->_gfx, this->_level);
}

gfx_config_t Pacman::GameCore::getConfig()
{
    return this->_levelConf;
}
