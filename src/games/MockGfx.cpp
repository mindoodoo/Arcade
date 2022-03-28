/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "MockGfx.hpp"

#include <utility>

void MockGfx::display() const
{
    refresh();
}

void MockGfx::flush() const
{
    clear();
}

void MockGfx::drawTile(int tile_index, int x, int y) const
{
    char c = this->_tileset.find(tile_index)->second;

    mvaddch(y, x * 2, c);
}

void MockGfx::drawText(const std::string &text, int x, int y) const
{
    mvaddstr(y, x, text.c_str());
}

MockGfx::MockGfx()
{
    initscr();
    raw();
    noecho();
    curs_set(0);
    halfdelay(1);
}

std::queue<char> &MockGfx::getInput()
{
    return this->_inputQueue;
}

void MockGfx::loadTileset(std::map<int, char> tileset)
{
    this->_tileset = std::move(tileset);
}

void MockGfx::popInput()
{
    this->_inputQueue.pop();
}

MockGfx::~MockGfx()
{
    curs_set(2);
}

void MockGfx::recordInputs()
{

    this->_inputQueue.push(getch());
}
