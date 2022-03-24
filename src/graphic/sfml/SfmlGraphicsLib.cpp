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

SfmlGraphicsLib::~SfmlGraphicsLib()
{
    window.close();
}

void SfmlGraphicsLib::createWindow(int width, int height)
{
    sf::CircleShape shape(200);

    while (window.isOpen()) 
    {
        sf::Event event;
        while (
            window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
  
        window.clear();
        window.draw(shape);
        window.display();
    }

}

void loadConfig(void)
{

}

void SfmlGraphicsLib::drawTile(int tile_index, int x, int y) const
{


}

void SfmlGraphicsLib::display() const
{

}

void SfmlGraphicsLib::flush() const
{

}

void SfmlGraphicsLib::drawText(const std::string &text, int x, int y) const
{

}

std::queue<char> & SfmlGraphicsLib::getInput()
{
    

}   

void SfmlGraphicsLib::checkConfig(const gfx_config_t &config)
{

}

