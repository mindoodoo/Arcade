/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>
#include "../../shared/IGraphicsLib.hpp"
#include "../../shared/shared.hpp"

#define NAME "sdl2"


class Sdl2GraphicsLib : public virtual IGraphicsLib
{
    public:
        Sdl2GraphicsLib();

        ~Sdl2GraphicsLib() override;

         // Updates screen with buffer (called at the end of all draw tiles)
        void display() override;
        // Clear screen/window

        //Runtime methods
        void flush()  override;
        void drawTile(int tile_index, int x, int y, int orientation = ORIENT_TOP) override;
        void drawText(const std::string &txt, int x, int y, rgb_t color) override;

        // Get events that happened since last frame
        // Queue of events
        std::queue<char> &getInput() override;

        /**
         * Saves all inputs to process to a queue
         * Call in Core at the beginning of everything
         */
        void recordInputs() override;
        void popInput() override;

        // Checks if game config is currently loaded config
        // If not : calls config loading methods
        void checkConfig(const gfx_config_t &config) override;
        void loadConfig();
        void loadTileset();

        std::string getName() override;

    private:
        gfx_config_t _config;
        std::queue<char> _inputQueue;
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Texture *_textTexture;
        SDL_Texture *_tilesetTexture;
        std::vector<SDL_Texture *> _tiles;
        SDL_Surface *_textSurface;
        SDL_Surface *_tilesetSurface;
        TTF_Font *_font;
        std::string _name;
};
