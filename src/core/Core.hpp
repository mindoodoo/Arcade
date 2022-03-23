/*
** EPITECH PROJECT, 2022
** Core.hpp
** File description:
** .
*/

#pragma once

#include "./loader/LdLoader.hpp"
#include "IGameLib.hpp"
#include "IGraphicsLib.hpp"



class Core
{
    public:
        explicit Core(const std::string &gfxPath = "./lib/arcade_ncurses.so");

        ~Core() = default;

        // Main loop
        void mainLoop();

    private:
        IGraphicsLib *_gfxPtr;
        IGameLib *_gamePtr;
        LDLoader<IGraphicsLib> _gfxLoader;
        LDLoader<IGameLib> _gameLoader;
};
