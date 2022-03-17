/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "SfmlGraphicsLib.hpp"

SfmlGraphicsLib::SfmlGraphicsLib()
{
    this->_window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
}

void SfmlGraphicsLib::display()
{
    this->_window->display();
}

SfmlGraphicsLib::~SfmlGraphicsLib()
{
    this->_window->close();
}

void SfmlGraphicsLib::drawTile(const std::string &path, int x, int y, int h, int w)
{
}

void SfmlGraphicsLib::drawTile(int x, int y, int h, int w, char c)
{
    sf::RectangleShape shape(sf::Vector2f(w, h));

    shape.setFillColor(sf::Color::Red);
    shape.setPosition(x, y);

    this->_window->draw(shape);
}

void SfmlGraphicsLib::showText(const std::string &text, int x, int y)
{
}

void SfmlGraphicsLib::flush()
{
    this->_window->clear();
}

void SfmlGraphicsLib::event()
{
    sf::Event event{};

    while (this->_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            this->_window->close();
    }
}
