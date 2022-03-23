/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <exception>
#include <string>

class GameError : public std::exception
{
        std::string _message;

    public:
        explicit GameError(std::string const &message);

        const char *what() const noexcept override;
};

class BuildError : virtual public GameError
{
        explicit BuildError(const std::string &message);
};
