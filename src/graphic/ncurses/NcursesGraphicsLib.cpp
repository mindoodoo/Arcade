/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/


#include "NcursesGraphicsLib.hpp"

NcursesGraphicsLib::NcursesGraphicsLib()
{
    // Initialize empty config
    this->_config = {
        "",
        "",
        "",
        0,
        0,
        0,
        0
    };

    initscr();
    raw();
    noecho();
    curs_set(0);
    halfdelay(1);
}

void NcursesGraphicsLib::checkConfig(const gfx_config_t &config)
{
    // Check if config is same
    if (config != this->_config) {
        this->_config = config;
        this->loadConfig();
    }
}

void NcursesGraphicsLib::loadConfig(void)
{
    auto csv = csvToTable(this->_config.asciiTilesetPath);

//    // Load tileset
//    for (unsigned int i = 0; i < csv.size(); i++)
//        for (unsigned int j = 0; j < csv[i].size(); j++)
//            this->_tileset.push_back(csv[i][j][0]); // [0] as it's a str
}

void NcursesGraphicsLib::flush(void) const
{
    clear();
}

void NcursesGraphicsLib::drawTile(int tile_index, int x, int y) const
{
    char c = this->_tileset.find(tile_index)->second;

    mvaddch(y, x * 2, c);
}

void NcursesGraphicsLib::drawText(const std::string &text, int x, int y) const
{
    mvprintw(y, x * 2, text.c_str());
}

std::queue<char> &NcursesGraphicsLib::getInput()
{
    // Add new input to queue
    this->_inputQueue.push(getch());

    return this->_inputQueue;
}

NcursesGraphicsLib::~NcursesGraphicsLib()
{
    curs_set(2);
}

void NcursesGraphicsLib::display() const
{
    refresh();
}

void NcursesGraphicsLib::popInput()
{
    this->_inputQueue.pop();
}
