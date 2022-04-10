/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "GameCore.hpp"

Nibbler::GameCore::GameCore()
    : BaseGameCore()
{
    this->_highScore = 0;  // TODO: Read from file where we save scores
    this->_level = 1;
    this->_state = GS_MENU;

    this->_levelConf = parseGfx(CONFIG_PATH);
    this->_maxLevels = csvToTable(CONFIG_PATH).size() - 2;

    this->_menuMap = parseMap(this->_levelConf.mapPath);
    this->_levelConf.windowWidth = this->_menuMap[0].size();
    this->_levelConf.windowHeight = this->_menuMap.size();
}

void Nibbler::GameCore::showMenu()
{
    rgb_t textColor = {240,24,24};

    GFX->checkConfig(this->_levelConf);

    // Draw core map
    for (size_t y = 0; y < this->_menuMap.size(); y++)
        for (size_t x = 0; x < this->_menuMap[y].size(); x++)
            GFX->drawTile(this->_menuMap[y][x].tile, x, y);

    GFX->drawText("WELCOME TO NIBBLER !", 25, 15, textColor);
    GFX->drawText("Press S to start playing...", 25, 17, textColor);
    GFX->drawText("Press Q to return to main menu...", 25, 18, textColor);
}

void Nibbler::GameCore::showGameOver()
{
    GFX->checkConfig(this->_levelConf);

    rgb_t textColor = {240,24,24};

    // Draw core map
    for (size_t y = 0; y < this->_menuMap.size(); y++)
        for (size_t x = 0; x < this->_menuMap[y].size(); x++)
            GFX->drawTile(this->_menuMap[y][x].tile, x, y);

    GFX->drawText("Game Over...", 25, 15, textColor);
    GFX->drawText("Press S to play again...", 25, 17, textColor);
    GFX->drawText("Press Q to return to main menu...", 25, 18, textColor);
}

void Nibbler::GameCore::startGame()
{
    this->_game = new Level(this->_gfx, this->_level);
}

gfx_config_t Nibbler::GameCore::getConfig()
{
    return this->_levelConf;
}
