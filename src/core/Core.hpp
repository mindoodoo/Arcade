/*
** EPITECH PROJECT, 2022
** GameCore.hpp
** File description:
** .
*/

#pragma once

#include <unordered_map>
#include "./loader/LdLoader.hpp"
#include "IGameLib.hpp"
#include "IGraphicsLib.hpp"

typedef struct
{
    std::string name;
} game_meta_t;


class Core
{
    public:
        explicit Core(const std::string &gfxPath = "./lib/arcade_ncurses.so");

        ~Core() = default;

        void launchGame();

        // Main loop
        void mainLoop();

    private:
        IGraphicsLib *_gfx;
        IGameLib *_gamePtr;
        LDLoader<IGraphicsLib> _gfxLoader;
        LDLoader<IGameLib> _gameLoader;
};
