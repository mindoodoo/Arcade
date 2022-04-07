/*
** EPITECH PROJECT, 2022
** GameCore.cpp
** File description:
** .
*/

#include <dirent.h>
#include <fstream>
#include <algorithm>
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

        // Get instances of game and gfx libraries
        this->_gfx = this->_gfxLoader.getInstance();

        this->loadAvailableLibs();

        // Init gfx config for menu
        this->_config = {
            "",
            "",
            "./assets/core/arial.ttf",
            32,
            32,
            40,
            40
        };

        this->_gamePtr = nullptr;
    } catch (std::exception &err) {
        std::cerr << err.what() << std::endl;
        exit(84);
    }
}

void Core::mainLoop()
{
    try {
        while (this->_state) {
            this->_gfx->recordInputs();
            this->handleArcadeInputs();
            this->_gfx->flush();

            if (this->_state == ARCADE::GAME) {
                if (this->_gamePtr->frame() != 0) {
                    this->_gfx->flush();
                    this->loadAvailableLibs();
                    this->_state = ARCADE::MENU;
                }
            } else {
                this->_gfx->checkConfig(this->_config);
                size_t i = 0;
                for (const auto &meta: this->_games) {
                    std::string line = std::to_string(i) + ". " + meta.name;
                    this->_gfx->drawText(i == this->_selectedGame ? line + " - selected" : line, 0, 0 + i);
                    i++;
                }

                this->displayScores();

                this->handleMenuInputs();
            }
            this->_gfx->display();
        }
    } catch (std::exception &err) {
        delete this->_gfx;
        delete this->_gamePtr;
        this->_state = ARCADE::HALT;
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

    this->_games = std::deque<game_meta_t>(0);
    this->_graphics = std::deque<graphic_meta_t>(0);

    while ((entry = readdir(dir)) != nullptr) {
        try {
            if (entry->d_name[0] != '.') {
                std::string path = dirPath + "/" + std::string(entry->d_name);

                void *handle = LDLoader<void>::open(path);

                void *result = LDLoader<void>::getSymbol(handle, "id");

                int type = *(int *) result;

                if (type == GAME_ID) {
                    result = LDLoader<void>::getSymbol(handle, "gameName");

                    std::string gameName = std::string((char *) result);
                    std::string assets = "./assets/" + gameName + "/";

                    game_meta_t game = {.name = gameName, .path = path, .assets = assets};

                    Core::getScores(assets, &game);

                    this->_games.push_back(game);
                } else if (type == GFX_iD) {
                    result = LDLoader<void>::getSymbol(handle, "name");
                    std::string gfxName = std::string((char *) result);

                    if (gfxName == this->_gfx->getName())
                        this->_graphics.push_front(graphic_meta_t{.name = gfxName, .path = path});
                    else
                        this->_graphics.push_back(graphic_meta_t{.name = gfxName, .path = path});
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
        case 'j':
            this->graphicsRotateLeft();
            break;
        case 'l':
            this->graphicsRotateRight();
            break;
    }
}

Core::~Core()
{
    delete this->_gfx;
    delete this->_gamePtr;
}

std::deque<int> Core::getScores(const std::string &assets, game_meta_t *game)
{
    std::deque<int> scores(0);
    try {
        std::vector<std::string> scoreboard = csvToVector(assets + "scoreboard");

        for (const auto &score_s: scoreboard) {
            int score = std::stoi(score_s);

            scores.insert(std::upper_bound(scores.begin(), scores.end(), score), score);
        }

        std::reverse(scores.begin(), scores.end());
        if (game) {
            game->latest_score = scoreboard.empty() ? NO_SCORE : std::stoi(scoreboard.back());
            game->scores = scores;
        }
    } catch (std::exception &err) {
        if (game) {
            game->latest_score = NO_SCORE;
            game->scores = scores;
        }
        std::cerr << err.what() << std::endl;
    }
    return scores;
}

void Core::displayScores()
{
    std::deque<int> scores = SELECTED_GAME.scores;

    std::string latest_score = SELECTED_GAME.latest_score == NO_SCORE ? "" : std::to_string(SELECTED_GAME.latest_score);
    this->_gfx->drawText("LATEST SCORE: " + latest_score, 20, 0);
    int offset = 2;
    this->_gfx->drawText("SCORES:", 20, offset);

    for (size_t i = 0; i < 10; i++) {
        std::string score = i < scores.size() ? std::to_string(scores[i]) : "";
        std::string line = std::to_string(i + 1) + ".\t" + score;
        this->_gfx->drawText(line, 20, i + offset + 1);
    }
}

void Core::graphicsRotateLeft()
{
    std::cout << "help" << std::endl;
    std::cout << this->_graphics[1].path << std::endl;
    if (this->_graphics.size() <= 1)
        return;
    delete this->_gfx;
    this->_gfxLoader.loadLib(this->_graphics[1].path);
    this->_gfx = this->_gfxLoader.getInstance();
    this->_gfx->checkConfig(this->_config);
    this->_graphics.push_back(this->_graphics.front());
    this->_graphics.pop_front();
}

void Core::graphicsRotateRight()
{
    std::cout << "help" << std::endl;
    std::cout << this->_graphics.back().path << std::endl;
    if (this->_graphics.size() <= 1)
        return;
    delete this->_gfx;
    this->_gfxLoader.loadLib(this->_graphics.back().path);
    this->_gfx = this->_gfxLoader.getInstance();
    this->_gfx->checkConfig(this->_config);
    this->_graphics.push_front(this->_graphics.back());
    this->_graphics.pop_back();
}
