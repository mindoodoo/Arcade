/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include "../../shared/IGraphicsLib.hpp"
#include "../../shared/shared.hpp"

#define NAME "sfml"

class SfmlGraphicsLib : public virtual IGraphicsLib
{
    public:
        // Constructor
        SfmlGraphicsLib();
        ~SfmlGraphicsLib();

        //config / view setup

        // Updates screen with buffer (called at the end of all draw tiles)
        virtual void display() override;
        // Clear screen/window

        //Runtime methods
        void flush(void)  override;
        void drawTile(int tile_index, int x, int y) override;
        void drawText(const std::string &txt, int x, int y) override;

        // Get events that happened since last frame
        // Queue of events
        std::queue<char> &getInput() override;

        /**
         * Saves all inputs to process to a queue
         * Call in Core at the beginning of everything
         */
        virtual void recordInputs() override;
        virtual void popInput() override;

        // Checks if game config is currently loaded config
        // If not : calls config loading methods
        virtual void checkConfig(const gfx_config_t &config) override;
        void loadConfig(void);
        void loadTileset();

        std::string getName() override;

    private:
        sf::Text _text;
        sf::Font _font;
        std::vector<sf::Sprite*> _tiles;
        sf::Texture _tilesetTexture;
        sf::RenderWindow _window;
        gfx_config_t _config;
        std::queue<char> _inputQueue;
        std::string _name;
};
