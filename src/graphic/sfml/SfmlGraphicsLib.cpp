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
    window.close();
}

void SfmlGraphicsLib::drawTile(int tile_index, int x, int y)
{


}

void SfmlGraphicsLib::display()
{
    window.display();
}

void SfmlGraphicsLib::flush() 
{
    window.clear(sf::Color::Black);
}

void SfmlGraphicsLib::drawText(const std::string &text, int x, int y) 
{
    this->_font.loadFromFile(this->_config.fontFolderPath);
    this->_text.setString(text);
    this->_text.setCharacterSize(24); // in pixels
    this->_text.setFillColor(sf::Color::Red);
    this->_text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    this->_text.setPosition(x,y);
    this->window.draw(_text);
}

std::queue<char> &SfmlGraphicsLib::getInput()
{
    sf::Event event{};
    char pressedKey;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close(); // Maybe more cleanup ? back to core menu ?
        else if (event.type == sf::Event::KeyPressed) {
            pressedKey = event.key.code + 'a';
            if (pressedKey >= 'a' && pressedKey <= 'z')
                this->_inputQueue.push(pressedKey);
            // If other special keys needed add if
        }
    }
    return this->_inputQueue;
}


void SfmlGraphicsLib::checkConfig(const gfx_config_t &config)
{
        // Check if config is same
    // if (config != this->_config) {
    //     this->_config = config;
    //     this->loadConfig();
    // }

}

void SfmlGraphicsLib::loadConfig(void)
{
    std::vector<std::string> stringVector = csvToVector(this->_config.graphicalTilesetPath);
    // std::vector<std::string> splitStringVector;

    // for (unsigned int i = 0; i < stringVector.size(); ++i) {
    //     splitStringVector = splitStr(stringVector[i], ";");
    //     tile.c = splitStringVector[0][0];
    //     if (splitStringVector.size() > 1)
    //         tile.color = getColor(splitStringVector[1]);
    //     else
    //         tile.color = COLOR_WHITE;
    //     this->_tileset.push_back(tile);
    // }
    this->_font.loadFromFile(this->_config.fontFolderPath);
    this->_text.setFont(this->_font);
    //this->window.create(sf::VideoMode(800,600), "Arcade SFML"); 
    this->window.create(sf::VideoMode(this->_config.windowWidth * this->_config.tileWidth,
    this->_config.windowHeight * this->_config.tileHeight), "Arcade SFML");
    this->window.setFramerateLimit(60);
}

void SfmlGraphicsLib::mocksetconfig(std::vector<std::string> configs)
{

    this->_config.asciiTilesetPath = configs[0];
    this->_config.graphicalTilesetPath = configs[1];
    this->_config.fontFolderPath = configs[2];
    this->_config.tileWidth = atoi(configs[3].c_str()); // In px
    this->_config.tileHeight = atoi(configs[4].c_str()); // In px
    this->_config.windowWidth = atoi(configs[5].c_str()); // In tiles
    this->_config.windowHeight = atoi(configs[6].c_str()); // In tiles

}

void SfmlGraphicsLib::popInput()
{
    this->_inputQueue.pop();
}

void SfmlGraphicsLib::recordInputs()
{
    // Add new input to queue
    //this->_inputQueue.push(getch());
}

