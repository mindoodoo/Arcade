/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "ArcadeError.hpp"

Error::Arcade::Arcade(const std::string &message)
{
    this->_message = message;
}

const char *Error::Arcade::what() const noexcept
{
    return this->_message.c_str();
}

Error::FileNotFound::FileNotFound(const std::string &filePath)
    : Arcade("File not found: " + filePath)
{
}

Error::GameNotFound::GameNotFound(size_t id)
    : Arcade("Game number " + std::to_string(id) + " not found.")
{
}

Error::NoGraphicsLib::NoGraphicsLib(const std::string &path) : Arcade("This is not a graphics library: " + path)
{
}
