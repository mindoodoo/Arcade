/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "GameErrors.hpp"

GameError::GameError(const std::string &message)
{
    this->_message = message;
}

const char *GameError::what() const noexcept
{
    return this->_message.c_str();
}

BuildError::BuildError(const std::string &gameName)
    : GameError(gameName + ": Error while launching game.")
{
}
