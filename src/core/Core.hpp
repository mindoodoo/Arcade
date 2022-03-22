/*
** EPITECH PROJECT, 2022
** Core.hpp
** File description:
** .
*/

#pragma once

#include "IGraphicsLib.hpp"
#include "IGameLib.hpp"
#include "./loader/LdLoader.hpp"

class Core {
    public:
        Core();
        ~Core();

        // Main loop
        void mainLoop(void);

    private:
        IGraphicsLib *_gfxPtr;
        IGameLib *_gamePtr;
        LDLoader<IGraphicsLib> _gfxLoader;
        LDLoader<IGameLib> _gameLoader;
};
