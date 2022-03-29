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
    this->window.create(sf::VideoMode(640,480), "Arcade SFML");
    this->window.setFramerateLimit(60);
}

// sf::RenderWindow SfmlGraphicsLib::getWindow()
// {
//     return this->window;
// }

SfmlGraphicsLib::~SfmlGraphicsLib()
{
    window.close();
}

void SfmlGraphicsLib::createWindow(int width, int height)
{

}

void loadConfig(void)
{

}

void SfmlGraphicsLib::drawTile(int tile_index, int x, int y) const
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

void SfmlGraphicsLib::drawText(const std::string &text, int x, int y) const
{

}

std::queue<char> & SfmlGraphicsLib::getInput()
{
     sf::Event event{};

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
        }
        else if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Z)
                this->_inputQueue.push('w');
            else if (event.key.code == sf::Keyboard::S)
                this->_inputQueue.push('s');
            else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Q)
                this->_inputQueue.push('a');
            else if (event.key.code == sf::Keyboard::D)
                this->_inputQueue.push('d');
        }
    }
    return this->_inputQueue;
    

}   

void SfmlGraphicsLib::checkConfig(const gfx_config_t &config)
{

}

