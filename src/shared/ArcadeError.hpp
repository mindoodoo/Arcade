/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <exception>
#include <string>

namespace Error
{
    class Arcade : virtual public std::exception
    {
            std::string _message;

        public:
            explicit Arcade(std::string const &message);

            const char *what() const noexcept override;
    };

    class FileNotFound : virtual public Arcade
    {
        public:
            explicit FileNotFound(const std::string &filePath);
    };

    class GameNotFound : virtual public Arcade
    {
        public:
            explicit GameNotFound(size_t id);
    };

    class NoGraphicsLib : virtual public Arcade
    {
        public:
            explicit NoGraphicsLib(const std::string &path);
    };
}
