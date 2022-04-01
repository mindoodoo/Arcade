/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_ARCADE_NICOLAS_LATTEMANN_SDL2GRAPHICSLIB_HPP
#define B_OOP_400_BER_4_1_ARCADE_NICOLAS_LATTEMANN_SDL2GRAPHICSLIB_HPP

#include "IGraphicsLib.hpp"

class Sdl2GraphicsLib : public virtual IGraphicsLib
{
    public:
        Sdl2GraphicsLib();

        ~Sdl2GraphicsLib();

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

    private:
    
        gfx_config_t _config;
        std::queue<char> _inputQueue;
};

#endif //B_OOP_400_BER_4_1_ARCADE_NICOLAS_LATTEMANN_SDL2GRAPHICSLIB_HPP
