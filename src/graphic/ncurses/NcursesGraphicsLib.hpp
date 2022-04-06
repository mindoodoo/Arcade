/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <ncurses.h>
#include <vector>
#include <iostream>
#include "../../shared/IGraphicsLib.hpp"
#include "../../shared/shared.hpp"

#define NAME "ncurses"

typedef struct {
    char c;
    int color;
} ascii_tile_t;

class NcursesGraphicsLib : virtual public IGraphicsLib
{
    public:
        ~NcursesGraphicsLib() override;

        // Constructor
        NcursesGraphicsLib();

        // Config / view setup
        void checkConfig(const gfx_config_t &config) override;

        void loadConfig();

        // Runtime methods
        void flush() override;

        void drawTile(int tile_index, int x, int y, int orientation = ORIENT_TOP) override;

        void drawText(const std::string &text, int x, int y, rgb_t color = {255,255,255}) override;

        // Do nothing function
        void display() override;

        // Input
        std::queue<char> &getInput() override;

        void popInput() override;

        void recordInputs() override;

        std::string getName() override;
    private:
        gfx_config_t _config;
        std::vector<ascii_tile_t> _tileset;
        std::queue<char> _inputQueue;
        std::string _name;
};
