/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <string>
#include <queue>

// Optionally add tileset width/height in tiles
typedef struct {
    std::string asciiTilesetPath;
    std::string graphicalTilesetPath;
    std::string fontFolderPath;
    int tileWidth; // In px
    int tileHeight; // In px
    int windowWidth; // In tiles
    int windowHeight; // In tiles
} gfx_config_t;

// Overloads
bool operator==(gfx_config_t const &left, gfx_config_t const &right);
bool operator!=(gfx_config_t const &left, gfx_config_t const &right);

class IGraphicsLib
{
    public:
        virtual ~IGraphicsLib() = default;

        // Updates screen with buffer (called at the end of all draw tiles)
        virtual void display() const = 0;

        // Draw tile of index tile_index, at x tile and y tile
        // (tile is the unit)
        // Note : Could add possibility for rotation of tile in the future
        virtual void drawTile(int tile_index, int x, int y) const = 0;

        // Draws text, at x tile and y tile
        virtual void drawText(const std::string &text, int x, int y) const = 0;

        // Get events that happened since last frame
        // Queue of events
        virtual std::queue<char> getInput() const = 0;

        // Checks if game config is currently loaded config
        // If not : calls config loading methods
        virtual void checkConfig(const gfx_config_t &config) = 0;
};