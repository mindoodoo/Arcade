/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <ncurses.h>
#include "GameManager.hpp"
#include "Core.hpp"
#include "../include/NibblerMacros.hpp"

GameManager::GameManager(IGraphicsLib **gfx)
{
    this->_score = 0;
    this->_gameHeight = 30;
    this->_gameWidth = 30;
    this->_scene = new Terrain(this->_gameHeight, this->_gameWidth, gfx);
    this->_nibbler = new Nibbler(this->_gameHeight / 2, this->_gameWidth / 2, this->_scene, gfx);
    this->_gfx = gfx;
    this->generateItems(ITEM_FRUIT, this->_gameHeight * this->_gameWidth * 0.01);
}

void GameManager::draw()
{
    this->_scene->draw();
    this->_nibbler->draw();

    for (const auto item: this->_items) {
        item->draw();
    }
}

int GameManager::frame()
{
    std::queue<char> inputs = GFX->getInput();

    if (!inputs.empty()) {
        char c = inputs.back();
        GFX->popInput();

        switch (c) {
            case 'z':
            case 'w':
                this->_nibbler->turn(0, -1);
                break;
            case 's':
                this->_nibbler->turn(0, 1);
                break;
            case 'q':
            case 'a':
                this->_nibbler->turn(-1, 0);
                break;
            case 'd':
                this->_nibbler->turn(1, 0);
                break;
        }
    }
    if (!this->_nibbler->moveForward())
        return GS_GAME_OVER;
    this->checkItemCollision();
    this->draw();
    return 0;
}

void GameManager::checkItemCollision()
{
    const segment_t head = this->_nibbler->head();

    for (Item *item: this->_items) {
        if (item->itemCollision(head.x, head.y)) {
            item->effect(this->_nibbler);
            std::pair<int, int> coords = this->randomLocation();
            item->relocate(coords.first, coords.second);
            this->_score++;
            break;
        }
    }
}

void GameManager::generateItems(int item_id, size_t amount)
{
    for (size_t i = 0; i < amount; i++) {
        std::pair<int, int> coords = this->randomLocation();
        Item *item = nullptr;

        switch (item_id) {
            case ITEM_FRUIT:
                item = new Fruit(coords.first, coords.second, this->_gfx);
        }

        this->_items.push_back(item);
    }
}

bool GameManager::isTileEmpty(int x, int y)
{
    for (auto item: this->_items)
        if (item->itemCollision(x, y))
            return false;
    if (!this->_scene->validLocation(x, y))
        return false;
    if (this->_nibbler->nibblerCollision(x, y))
        return false;
    return true;
}

std::pair<int, int> GameManager::randomLocation()
{
    int x;
    int y;

    size_t maxTries = (this->_gameHeight - 2) * (this->_gameWidth - 2) - this->_nibbler->length() - this->_items.size();

    for (size_t i = 0; i < maxTries || !this->isTileEmpty(x, y); i++) {
        x = random() % (this->_gameWidth - 2) + 1;
        y = random() % (this->_gameHeight - 2) + 1;
    }

    return {x, y};
}

int GameManager::getScore() const
{
    return this->_score;
}
