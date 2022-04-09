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
#include "../shared/shared.hpp"
#include "CoreMacros.hpp"

#define SELECTED_GAME this->_games[this->_selectedGame]
#define NO_SCORE -1

typedef struct
{
    std::string name;
    std::string path;
    std::string assets;
    std::deque<int> scores = std::deque<int>(0);
    int latest_score = NO_SCORE;
} game_meta_t;

typedef struct
{
    std::string name;
    std::string path;
} graphic_meta_t;

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

        ~Core();

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
         * Handles all the menu only inputs, like launching a game with space
         * is in charge of closing the program by setting _state to HALT
         */
        void handleMenuInputs();

        /**
         * Handles inputs for swapping game or graphics library
         * while in game or selected a game while in the arcade menu
         */
        void handleArcadeInputs();

        /**
         * loads all game libraries in ./libs
         * to display them in the menu
         * Called on startup, on 'r' press and maybe also on game close
         */
        void loadAvailableLibs();

        /**
         * loads all scores and puts them into a sorted deque
         * adds the sorted scores and most recent score to game_meta_t if given
         * @param assets
         * @return sorted scores
         */
        static std::deque<int> getScores(const std::string &assets, game_meta_t *game);

        /**
         * Displays the scores of the currently selected games
         */
        void displayScores();

        /**
         * the last element of the graphics array becomes the active one
         */
        void graphicsRotateLeft();

        /**
         * the second element of the graphics array becomes the active one
         */
        void graphicsRotateRight();

        /**
         * loads currently selected graphical library
         */
        void loadGraphics();

        IGraphicsLib *_gfx;
        IGameLib *_gamePtr;

        LDLoader<IGraphicsLib> _gfxLoader;
        LDLoader<IGameLib> _gameLoader;

        // holds all available games and graphical libraries
        std::deque<game_meta_t> _games;
        std::deque<graphic_meta_t> _graphics;

        // holds the arcade State, refer to the var type for more info
        ARCADE _state;

        // holds the index of the selected game
        size_t _selectedGame = 0;
        size_t _selectedGraphics = 0;

        // Config specifically to set size of menu in tiles and tile size
        gfx_config_t _config;

        std::vector<std::vector<gfx_tile_t>> _menuMap;
};
