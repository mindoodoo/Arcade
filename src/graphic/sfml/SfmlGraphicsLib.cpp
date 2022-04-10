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
        "",
        0,
        0,
        0,
        0,
        0
    };

    this->_name = NAME;
}

SfmlGraphicsLib::~SfmlGraphicsLib()
{
    this->_window.close();

    // Free Sprite pointers
    for (unsigned int i = 0; i < this->_tiles.size(); ++i)
        delete this->_tiles[i];
}

void SfmlGraphicsLib::drawTile(int tile_index, int x, int y, int orientation)
{
    sf::Sprite *tile = this->_tiles[tile_index];
    int pixelPosX = x * this->_config.tileWidth + (this->_config.tileWidth / 2);
    int pixelPosY = y * this->_config.tileHeight + (this->_config.tileHeight / 2);

    // Set position, orientation and draw sprite
    tile->setPosition(pixelPosX, pixelPosY);
    tile->setRotation(90 * orientation);
    this->_window.draw(*tile);

    // Reset orientation for future use
    tile->setRotation(0);
}

void SfmlGraphicsLib::loadTileset()
{
    sf::Vector2u tilesetSize;
    // sf::Texture *newTexture;
    sf::Sprite *newSprite;
    sf::IntRect tileRect = {0, 0, this->_config.tileWidth,
                            this->_config.tileHeight};
    int x_origin = this->_config.tileWidth / 2;
    int y_origin = this->_config.tileHeight / 2;
    int x;
    int y;

    // Clear previous tileset
    this->_tiles.clear();

    if (this->_config.graphicalTilesetPath == "")
        return;
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

                // Load new tile texture and apply to sprite
                newSprite = new sf::Sprite(this->_tilesetTexture, tileRect);
                // Set transformation origin to middle of tile
                newSprite->setOrigin(x_origin, y_origin);

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

void SfmlGraphicsLib::drawText(const std::string &text, int x, int y, rgb_t color)
{
    sf::Color textColor = sf::Color(color.r, color.g, color.b);

    this->_text.setString(text);
    this->_text.setFillColor(textColor);
    this->_text.setPosition(x * this->_config.tileWidth, y * this->_config.tileHeight);
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

void SfmlGraphicsLib::loadConfig()
{
    // Font stuff
    this->_font.loadFromFile(
        this->_config.fontFolderPath); // Considered single font file but in future multiple fonts potentially
    this->_text.setFont(this->_font);
    this->_text.setCharacterSize(this->_config.tileWidth);

    // Window creation
    std::cout << "Window dimensions are : " << this->_config.windowWidth * this->_config.tileWidth << ":"
              << this->_config.windowHeight * this->_config.tileHeight << std::endl;
    this->_window.create(sf::VideoMode(this->_config.windowWidth * this->_config.tileWidth,
                                       this->_config.windowHeight * this->_config.tileHeight), "Arcade SFML");
    this->_window.setFramerateLimit(60);

    // Load tileset
    this->loadTileset();
}

void SfmlGraphicsLib::popInput()
{
    if (!this->_inputQueue.empty())
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
            if (event.key.code == sf::Keyboard::Space)
                this->_inputQueue.push(' ');
            // If other special keys needed add if
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // This should change
}

std::string SfmlGraphicsLib::getName()
{
    return this->_name;
}
