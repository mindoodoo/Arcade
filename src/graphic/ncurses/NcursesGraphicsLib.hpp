/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <curses.h>
#include <vector>
#include "IGraphicsLib.hpp"

class NcursesGraphicsLib : virtual public IGraphicsLib
{
    public:
        // Constructor
        NcursesGraphicsLib();

        // Config / view setup
        void checkConfig(const gfx_config_t &config) override;

        void loadConfig(void);

        // Runtime methods
        void flush(void) const override;

    private:
        gfx_config_t _config;
        std::vector<char> _tileset;
};
