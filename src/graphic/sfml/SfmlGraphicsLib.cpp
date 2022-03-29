/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "SfmlGraphicsLib.hpp"

SfmlGraphicsLib::SfmlGraphicsLib()
{
    this->_config = {
        "",
        "",
        "",
        0,
        0,
        0,
        0
    };
}

SfmlGraphicsLib::~SfmlGraphicsLib()
{
    this->_window.close();

    // Free Sprite pointers
    for (unsigned int i = 0; i < this->_tiles.size(); ++i)
        delete this->_tiles[i];
}

void SfmlGraphicsLib::drawTile(int tile_index, int x, int y)
{
    sf::Sprite *tile = this->_tiles[tile_index];
    // sf::Vector2u

    // Set position and draw sprite
    tile->setPosition(x * this->_config.tileWidth,
    y * this->_config.tileHeight);
    this->_window.draw(*tile);
}

void SfmlGraphicsLib::loadTileset()
{
    sf::Vector2u tilesetSize;
    // sf::Texture *newTexture;
    sf::Sprite *newSprite;
    sf::IntRect tileRect = {0, 0, this->_config.tileWidth,
    this->_config.tileHeight};
    int x;
    int y;

    if (!this->_tilesetTexture.loadFromFile(this->_config.graphicalTilesetPath))
        std::cout << "ERROR LOADING TILESET IMAGE" << std::endl;
    else {
        // Get tileset width and height in tiles
        tilesetSize = this->_tilesetTexture.getSize();
        x = tilesetSize.x / this->_config.tileWidth;
        y = tilesetSize.y / this->_config.tileHeight;

        for (int i = 0; i < y; i++)
            for (int j = 0; j < x; j++) {
                // Update targeted part of the image
                tileRect.left = j * this->_config.tileWidth;
                tileRect.top = i * this->_config.tileHeight;

                // Load tile texture, apply to sprite and push to vector
                // newTexture = new sf::Texture();
                newSprite = new sf::Sprite(this->_tilesetTexture, tileRect);
                this->_tiles.push_back(newSprite);
            }
    }
}

void SfmlGraphicsLib::display()
{
    this->_window.display();
}

void SfmlGraphicsLib::flush() 
{
    this->_window.clear(sf::Color::Black);
}

void SfmlGraphicsLib::drawText(const std::string &text, int x, int y) 
{
    this->_text.setString(text);
    this->_text.setCharacterSize(24); // in pixels
    this->_text.setFillColor(sf::Color::Red);
    this->_text.setPosition(x * this->_config.tileWidth,
    y * this->_config.tileHeight);
    this->_window.draw(this->_text);
}

std::queue<char> &SfmlGraphicsLib::getInput()
{
    return this->_inputQueue;
}


void SfmlGraphicsLib::checkConfig(const gfx_config_t &config)
{
    // Check if config is same
    if (config != this->_config) {
        this->_config = config;
        this->loadConfig();
    }
}

void SfmlGraphicsLib::loadConfig(void)
{
    this->_font.loadFromFile(this->_config.fontFolderPath); // Considered single font file but in future multiple fonts potentially
    this->_text.setFont(this->_font);

    this->_window.create(sf::VideoMode(this->_config.windowWidth * this->_config.tileWidth,
    this->_config.windowHeight * this->_config.tileHeight), "Arcade SFML");

    this->_window.setFramerateLimit(60);

    this->loadTileset();
}

void SfmlGraphicsLib::popInput()
{
    this->_inputQueue.pop();
}

void SfmlGraphicsLib::recordInputs()
{
    sf::Event event{};
    char pressedKey;

    while (this->_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            this->_window.close(); // Maybe more cleanup ? back to core menu ?
        else if (event.type == sf::Event::KeyPressed) {
            pressedKey = event.key.code + 'a';
            if (pressedKey >= 'a' && pressedKey <= 'z')
                this->_inputQueue.push(pressedKey);
            // If other special keys needed add if
        }
    }
}
