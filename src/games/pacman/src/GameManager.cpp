/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "GameManager.hpp"
#include "../../GenericCore.hpp"

GameManager::GameManager() {
    this->_score = 0;
    this->_gameHeight = 0;
    this->_gameWidth = 0;

}

int GameManager::frame()
{
    this->_score++;

    if (this->_score == 50000) {
        return GS_GAME_OVER;
    }

    return GS_IN_GAME;
}

int GameManager::getScore() const
{
    return this->_score;
}
