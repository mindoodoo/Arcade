/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once
#include <string>
#include <queue>
#include <map>

#define GFX (*this->_gfx)

// Optionally add tileset width/height in tiles
typedef struct {
    std::string asciiTilesetPath;
    std::string graphicalTilesetPath;
    std::string fontFolderPath;
    std::string mapPath;
    int tileWidth; // In px
    int tileHeight; // In px
    int windowWidth; // In tiles
    int windowHeight; // In tiles
    int scale;
} gfx_config_t;

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} rgb_t;

// Overloads
bool operator==(gfx_config_t const &left, gfx_config_t const &right);
bool operator!=(gfx_config_t const &left, gfx_config_t const &right);

#define ORIENT_TOP 0
#define ORIENT_RIGHT 1
#define ORIENT_BOTTOM 2
#define ORIENT_LEFT 3

class IGraphicsLib
{
    public:
        virtual ~IGraphicsLib() = default;

        // Updates screen with buffer (called at the end of all draw tiles)
        virtual void display() = 0;

        // Clear screen/window
        virtual void flush() = 0;

        // Draw tile of index tile_index, at x tile and y tile
        // (tile is the unit)
        // Note : Could add possibility for rotation of tile in the future
        virtual void drawTile(int tile_index, int x, int y, int orientation = ORIENT_TOP) = 0;

        // Draws text, at x tile and y tile
        virtual void drawText(const std::string &text, int x, int y, rgb_t color = {255,255,255}) = 0;

        /**
         * Saves all inputs to process to a queue
         * Call in Core at the beginning of everything
         */
        virtual void recordInputs() = 0;

        /**
         * Returns all inputs recorded
         * @return std::queue<char>
         */
        virtual std::queue<char> &getInput() = 0;

        virtual void popInput() = 0;

        /**
         * Checks if game config is currently loaded config
         * If not : loads config
         * @param config
         */
        virtual void checkConfig(const gfx_config_t &config) = 0;

        virtual std::string getName() = 0;
};
