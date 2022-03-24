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
#include "../../shared/IGraphicsLib.hpp"

class SfmlGraphicsLib : public virtual IGraphicsLib
{
    public:
        // Constructor
        SfmlGraphicsLib();
        ~SfmlGraphicsLib();

        //config / view setup

        void loadConfig(void);

        //create window
        void createWindow(int width, int height);

        // Updates screen with buffer (called at the end of all draw tiles)
        virtual void display() const override;
        // Clear screen/window

        //Runtime methods
        void flush(void) const override;
        void drawTile(int tile_index, int x, int y) const override;
        void drawText(const std::string &text, int x, int y) const override;

        // Get events that happened since last frame
        // Queue of events
        std::queue<char> &getInput() override;
        
        // Checks if game config is currently loaded config
        // If not : calls config loading methods
        virtual void checkConfig(const gfx_config_t &config) override;



    private:
        gfx_config_t _config;
        sf::RenderWindow window;




};
