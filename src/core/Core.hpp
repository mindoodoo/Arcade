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
    std::string path;
} meta_t;

enum ARCADE
{
    HALT = 0,
    MENU = 1,
    GAME = 2
};

class Core
{
    public:
        explicit Core(const std::string &gfxPath = "./lib/arcade_ncurses.so");

        ~Core() = default;

        /**
         * main loop of the program
         */
        void mainLoop();

    private:

        /**
         * launches the currently "selected" game
         * the "selected" game is whichever is selected in the
         * arcade menu during runtime
         */
        void launchGame();

        /**
         * Handles all the Arcade machine related inputs,
         * is in charge of closing the program by setting _state to HALT
         */
        void handleInputs();

        /**
         * Handles inputs for swapping game or graphics library
         * while in game
         */
        void handleInputsInGame();

        /**
         * loads all game libraries in ./libs
         * to display them in the menu
         */
        void loadAvailableLibs();


        IGraphicsLib *_gfx;
        IGameLib *_gamePtr;

        LDLoader<IGraphicsLib> _gfxLoader;
        LDLoader<IGameLib> _gameLoader;

        std::deque<meta_t> _games;
        std::deque<meta_t> _graphics;

        int _state;

        size_t _selectedGame = 0;
};
