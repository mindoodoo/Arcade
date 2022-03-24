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

            this->handleInputs();

            this->_gfx->drawText(std::to_string(_selectedGame), 20, 20);

            this->_gfx->flush();
        }
    }
}

void Core::launchGame()
{
    if (this->_selectedGame >= this->_games.size()) {
        delete this->_gfx;
        throw Error::GameNotFound(this->_selectedGame);
    }

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

    while ((entry = readdir(dir)) != nullptr) {
        if (entry->d_name[0] != '.') {
            std::string path = dirPath + "/" + std::string(entry->d_name);

            void *handle = dlopen(path.c_str(), RTLD_NOW);

            if (handle == nullptr)
                continue;

            void *result = dlsym(handle, "id");

            if (result == nullptr) {
                std::cerr << "reee";
                std::cerr << dlerror();

                exit(84);
                continue;
            }

            int type = *(int *) result;

            if (type == GAME_ID) {
                this->_games.push_back(meta_t{.name = path, .path = path});
            } else if (type == GFX_iD) {
                this->_graphics.push_back(meta_t{.name = path, .path = path});
            }
        }
    }
    closedir(dir);
}

void Core::handleInputs()
{
    std::queue<char> inputs = this->_gfx->getInput();

    if (inputs.empty())
        return;
    switch (inputs.back()) {
        // game selection section
        case 'z': // goes up by one game
        case 'w':
            if (this->_selectedGame > 0)
                this->_selectedGame--;
            else
                this->_selectedGame = this->_games.size() - 1;
            break;
        case 's': // goes down by one game
            if (this->_selectedGame == (this->_games.size() - 1))
                this->_selectedGame = 0;
            else
                this->_selectedGame++;
            break;
        case 'l': // launches the selected game
            this->_gfx->flush();
            this->_gfx->popInput();
            this->launchGame();
            break;
        case 'q': // quits the program
            this->_state = ARCADE::HALT;
    }
    this->_gfx->popInput();
}
