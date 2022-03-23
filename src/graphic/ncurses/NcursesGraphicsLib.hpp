/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <curses.h>
#include <vector>
#include "../../shared/IGraphicsLib.hpp"
#include "../../shared/shared.hpp"

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
        void flush() const override;

        void drawTile(int tile_index, int x, int y) const override;

        void drawText(const std::string &text, int x, int y) const override;

        // Do nothing function
        virtual void display() const;

        // Input
        std::queue<char> &getInput() override;

    private:
        gfx_config_t _config;
        std::vector<char> _tileset;
        std::queue<char> _inputQueue;
};
