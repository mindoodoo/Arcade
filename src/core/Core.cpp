/*
** EPITECH PROJECT, 2022
** GameCore.cpp
** File description:
** .
*/

#include <dirent.h>
#include "Core.hpp"
#include "map"
#include "shared.hpp"
#include "ArcadeError.hpp"

Core::Core(const std::string &gfxPath)
{
    try {
        this->_selectedGame = 0;
        this->_state = ARCADE::MENU;

        this->_gfxLoader.loadLib(gfxPath);
        this->loadAvailableLibs();

        // Get instances of game and gfx libraries
        this->_gfx = this->_gfxLoader.getInstance();
        this->_gamePtr = nullptr;
    } catch (std::exception &err) {
        std::cerr << err.what() << std::endl;
        exit(84);
    }
}

void Core::mainLoop()
{
    while (this->_state) {
        this->_gfx->recordInputs();
        this->handleArcadeInputs();
        this->_gfx->flush();

        if (this->_state == ARCADE::GAME) {
            if (this->_gamePtr->frame() != 0) {
                this->_gfx->flush();
                this->_state = ARCADE::MENU;
            }
        } else {
            size_t i = 0;
            for (const auto &meta: this->_games) {
                std::string line = std::to_string(i) + ". " + meta.name;
                this->_gfx->drawText(i == this->_selectedGame ? line + " - selected" : line, 0, 0 + i);
                i++;
            }

            this->handleMenuInputs();
        }
    }
}

void Core::launchGame()
{
    if (this->_selectedGame >= this->_games.size()) {
        delete this->_gfx;
        throw Error::GameNotFound(this->_selectedGame);
    }

    this->_gfx->flush();

    this->_gameLoader.loadLib(this->_games[this->_selectedGame].path);

    this->_gamePtr = this->_gameLoader.getInstance();

    this->_gamePtr->setGfx(&this->_gfx);

    this->_state = ARCADE::GAME;
}

void Core::loadAvailableLibs()
{
    struct dirent *entry;
    std::string dirPath = "./lib";
    DIR *dir = opendir(dirPath.c_str());

    if (!dir) {
        std::cerr << "Directory not found" << std::endl;
        return;
    }

    this->_games = std::deque<meta_t>(0);
    this->_graphics = std::deque<meta_t>(0);

    while ((entry = readdir(dir)) != nullptr) {
        try {
            if (entry->d_name[0] != '.') {
                std::string path = dirPath + "/" + std::string(entry->d_name);

                void *handle = LDLoader<void>::open(path);

                void *result = LDLoader<void>::getSymbol(handle, "id");

                int type = *(int *) result;

                if (type == GAME_ID) {
                    this->_games.push_back(meta_t{.name = path, .path = path});
                } else if (type == GFX_iD) {
                    this->_graphics.push_back(meta_t{.name = path, .path = path});
                }

                LDLoader<void>::close(handle);
            }
        } catch (std::exception &err) {
            std::cerr << err.what() << std::endl;
        }
    }
    closedir(dir);
}

void Core::handleMenuInputs()
{
    std::queue<char> inputs = this->_gfx->getInput();

    if (inputs.empty())
        return;
    switch (inputs.back()) {
        case ' ': // launches the selected game
            this->_gfx->popInput();
            this->launchGame();
            break;
        case 'q': // quits the program
            this->_state = ARCADE::HALT;
    }
}

void Core::handleArcadeInputs()
{
    std::queue<char> inputs = this->_gfx->getInput();

    if (inputs.empty())
        return;
    switch (inputs.back()) {
        // game selection section
        case 'i': // goes up by one game
            if (this->_selectedGame > 0)
                this->_selectedGame--;
            else
                this->_selectedGame = this->_games.size() - 1;
            this->_gfx->popInput();
            if (this->_state == ARCADE::GAME)
                this->launchGame();
            break;
        case 'k': // goes down by one game
            if (this->_selectedGame == (this->_games.size() - 1))
                this->_selectedGame = 0;
            else
                this->_selectedGame++;
            this->_gfx->popInput();
            if (this->_state == ARCADE::GAME)
                this->launchGame();
            break;
        case 'r': // reload list of libs
            this->loadAvailableLibs();
            break;
        case 'j': // TODO goes "left" by one graphics lib
            this->_gfx->popInput();
            break;
        case 'l': // TODO goes "right" by one graphics lib
            this->_gfx->popInput();
            break;
    }
}

Core::~Core()
{
    delete this->_gfx;
    delete this->_gamePtr;
}
