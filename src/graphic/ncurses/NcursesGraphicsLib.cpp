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

    // Init ncurses
    initscr();
    raw();
    noecho();
    curs_set(0);
    halfdelay(1);
    start_color();

    // Init color pairs
    init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);

    this->_name = NAME;
}

void NcursesGraphicsLib::checkConfig(const gfx_config_t &config)
{
    // Check if config is same
    if (config != this->_config) {
        this->_config = config;
        this->loadConfig();
    }
}

std::vector<std::string> splitStr(std::string str, std::string sep)
{
    std::vector<std::string> output;
    size_t start = 0;
    size_t end;
    std::string token;

    while ((end = str.find(sep, start)) != std::string::npos) {
        token = str.substr(start, end - start);
        start = end + sep.length();
        output.push_back (token);
    }
    output.push_back(str.substr (start));

    return output;
}

int getColor(std::string colorName)
{
    if (colorName == "BLACK")
        return COLOR_BLACK;
    if (colorName == "RED")
        return COLOR_RED;
    if (colorName == "GREEN")
        return COLOR_GREEN;
    if (colorName == "YELLOW")
        return COLOR_YELLOW;
    if (colorName == "BLUE")
        return COLOR_BLUE;
    if (colorName == "MAGENTA")
        return COLOR_MAGENTA;
    if (colorName == "CYAN")
        return COLOR_CYAN;
    if (colorName == "WHITE")
        return COLOR_WHITE;
    return COLOR_WHITE;
}

void NcursesGraphicsLib::loadConfig()
{
    if (this->_config.asciiTilesetPath == "")
        return;

    std::vector<std::string> stringVector = csvToVector(this->_config.asciiTilesetPath);
    std::vector<std::string> splitStringVector;
    ascii_tile_t tile;

    for (unsigned int i = 0; i < stringVector.size(); ++i) {
        splitStringVector = splitStr(stringVector[i], ";");
        tile.c = splitStringVector[0][0];
        if (splitStringVector.size() > 1)
            tile.color = getColor(splitStringVector[1]);
        else
            tile.color = COLOR_WHITE;
        this->_tileset.push_back(tile);
    }
}

void NcursesGraphicsLib::flush()
{
    clear();
}

void NcursesGraphicsLib::drawTile(int tile_index, int x, int y)
{
    attron(COLOR_PAIR(this->_tileset[tile_index].color));
    mvaddch(y, x * 2, this->_tileset[tile_index].c);
    attroff(COLOR_PAIR(this->_tileset[tile_index].color));
}

void NcursesGraphicsLib::drawText(const std::string &text, int x, int y)
{
    mvprintw(y, x * 2, text.c_str());
}

std::queue<char> &NcursesGraphicsLib::getInput()
{
    return this->_inputQueue;
}

NcursesGraphicsLib::~NcursesGraphicsLib()
{
    curs_set(2);
    endwin();
}

void NcursesGraphicsLib::display()
{
    refresh();
}

void NcursesGraphicsLib::popInput()
{
    this->_inputQueue.pop();
}

void NcursesGraphicsLib::recordInputs()
{
    // Add new input to queue
    this->_inputQueue.push(getch());
}

std::string NcursesGraphicsLib::getName()
{
    return this->_name;
}
