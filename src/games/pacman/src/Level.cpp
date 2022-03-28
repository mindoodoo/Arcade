/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "Level.hpp"
#include "../../BaseGameCore.hpp"

Pacman::Level::Level() {
    this->_score = 0;
    this->_gameHeight = 0;
    this->_gameWidth = 0;

}

int Pacman::Level::frame()
{
    this->_score++;

    if (this->_score == 50000) {
        return GS_GAME_OVER;
    }

    return GS_IN_GAME;
}

int Pacman::Level::getScore() const
{
    return this->_score;
}
