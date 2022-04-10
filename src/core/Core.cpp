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
    this->_selectedGame = 0;
    this->_selectedGraphics = 0;
    this->_state = ARCADE::MENU;

    this->_gfxLoader.loadLib(gfxPath);
    if (this->_gfxLoader.getId() != GFX_iD)
        throw Error::NoGraphicsLib(gfxPath);
    // Get instances of game and gfx libraries
    this->_gfx = this->_gfxLoader.getInstance();

    this->loadAvailableLibs();

    // Init gfx config for menu
    this->_config = parseGfx("./assets/core/graphics_cfg.csv");

    // Parse core menu map
    this->_menuMap = parseMap(this->_config.mapPath);
    this->_config.windowWidth = this->_menuMap[0].size();
    this->_config.windowHeight = this->_menuMap.size();

    this->_gamePtr = nullptr;
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
                    this->_gfx->checkConfig(this->_config);
                    this->loadAvailableLibs();
                    this->_state = ARCADE::MENU;
                }
            } else {
                this->_gfx->checkConfig(this->_config);

                // Draw core map
                for (size_t y = 0; y < this->_menuMap.size(); y++)
                    for (size_t x = 0; x < this->_menuMap[y].size(); x++)
                        this->_gfx->drawTile(this->_menuMap[y][x].tile, x, y);

                size_t i = 0;
                rgb_t textColor = {123, 60, 0};
                rgb_t selectedColor = {181, 49, 33};

                this->_gfx->drawText("GAMES:", 9, 10, textColor);

                for (const auto &meta: this->_games) {
                    std::string name = meta.name;
                    name[0] = toupper(name[0]);

                    this->_gfx->drawTile(i == this->_selectedGame ? GAME_SELECTED : GAME_UNSELECTED, 7, 13 + i * 2);
                    this->_gfx->drawText(name, 9, 13 + i * 2, i == this->_selectedGame ? selectedColor : textColor);
                    i++;
                }

                this->displayScores();

                this->handleMenuInputs();
            }
            this->_gfx->display();
        }
    } catch (std::exception &err) {
        std::cerr << err.what() << std::endl;
        this->_state = ARCADE::HALT;
    }
}

void Core::launchGame()
{
    if (this->_selectedGame >= this->_games.size())
        throw Error::GameNotFound(this->_selectedGame);

    this->_gameLoader.loadLib(this->_games[this->_selectedGame].path);

    this->_gamePtr = this->_gameLoader.getInstance();

    this->_gamePtr->setGfx(&this->_gfx);

    this->_gfx->checkConfig(this->_gamePtr->getConfig());

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
            this->_gfx->popInput();
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
            this->_gfx->popInput();
            break;
        case 'j':
            this->graphicsRotateLeft();
            this->_gfx->popInput();
            break;
        case 'l':
            this->graphicsRotateRight();
            this->_gfx->popInput();
            break;
    }
}

Core::~Core()
{
    this->_gfxLoader.closeLoadedLib();
    this->_gameLoader.closeLoadedLib();

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
    // this->_gfx->drawText("LATEST SCORE: " + latest_score, 20, 0);
    rgb_t textColor = {123, 60, 0};
    int offset = 9;
    this->_gfx->drawText("SCORES:", 47, offset - 1, textColor);

    for (size_t i = 0; i < 5; i++) {
        std::string score = i < scores.size() ? std::to_string(scores[i]) : " ";
        this->_gfx->drawTile(SMALL_CLOUD, 46, i * 2 + offset + 1);
        this->_gfx->drawText(score, 48, i * 2 + offset + 1, textColor);
    }
}

void Core::graphicsRotateLeft()
{
    if (this->_graphics.size() <= 1)
        return;

    this->_selectedGraphics--;

    if (this->_selectedGraphics > (this->_graphics.size() - 1))
        this->_selectedGraphics = this->_graphics.size() - 1;

    this->loadGraphics();
}

void Core::graphicsRotateRight()
{
    if (this->_graphics.size() <= 1)
        return;

    this->_selectedGraphics++;

    if (this->_selectedGraphics > (this->_graphics.size() - 1))
        this->_selectedGraphics = 0;
    this->loadGraphics();
}

void Core::loadGraphics()
{
    delete this->_gfx;

    this->_gfxLoader.clear();
    this->_gfxLoader.loadLib(this->_graphics[this->_selectedGraphics].path);
    if (this->_gfxLoader.getId() != GFX_iD)
        throw Error::GameNotFound(this->_selectedGame);

    this->_gfx = this->_gfxLoader.getInstance();

    if (this->_state == ARCADE::GAME)
        this->_gfx->checkConfig(this->_gamePtr->getConfig());
    else
        this->_gfx->checkConfig(this->_config);
}
