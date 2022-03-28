/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <map>
#include "../shared/IGraphicsLib.hpp"
#include "ncurses.h"

class MockGfx : public virtual IGraphicsLib
{
    public:
        ~MockGfx() override;

        MockGfx();

        void display() const override;

        void flush() const override;

        void drawTile(int tile_index, int x, int y) const override;

        void drawText(const std::string &text, int x, int y) const override;

        std::queue<char> &getInput() override;

        void loadTileset(std::map<int, char> tileset);

        void popInput() override;

        void recordInputs() override;

        void checkConfig(const gfx_config_t &config) override {
            std::string(config.graphicalTilesetPath) ;
        };
    private:
        std::queue<char> _inputQueue;

        std::map<int, char> _tileset;
};
