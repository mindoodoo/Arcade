/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <ncurses.h>
#include <utility>
#include "Level.hpp"
#include "GameCore.hpp"
#include "../include/NibblerMacros.hpp"

Nibbler::Level::Level(IGraphicsLib **gfx, gfx_config_t levelConf)
{
    this->_score = 0;
    this->_levelConf = std::move(levelConf);

    this->_gameHeight = 30;
    this->_gameWidth = 30;

    this->_scene = new Terrain(this->_gameHeight, this->_gameWidth, gfx);
    this->_nibbler = new Player(this->_gameHeight / 2, this->_gameWidth / 2, this->_scene, gfx);

    this->_gfx = gfx;

    this->_state = LEVEL::RUNNING;

    this->generateItems(ITEM_FRUIT, this->_gameHeight * this->_gameWidth * 0.1);
}

void Nibbler::Level::draw()
{
    this->_scene->draw();
    this->_nibbler->draw();

    for (const auto item: this->_items) {
        item->draw();
    }
}

int Nibbler::Level::frame()
{
    GFX->checkConfig(this->_levelConf);

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
        this->_state = LEVEL::DEFEAT;
    this->checkItemCollision();
    this->draw();
    return this->_state;
}

void Nibbler::Level::checkItemCollision()
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

void Nibbler::Level::generateItems(int item_id, size_t amount)
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

bool Nibbler::Level::isTileEmpty(int x, int y)
{
    if (!this->_scene->validLocation(x, y))
        return false;
    for (auto item: this->_items)
        if (item->itemCollision(x, y))
            return false;
    if (this->_nibbler->nibblerCollision(x, y))
        return false;
    return true;
}

std::pair<int, int> Nibbler::Level::randomLocation()
{
    int x;
    int y;

    x = random() % (this->_gameWidth - 2) + 1;
    y = random() % (this->_gameHeight - 2) + 1;

    if (!this->isTileEmpty(x, y)) {
        std::pair<int, int> pair = circleScan(30, x, y);

        if (pair.first == -1) {
            this->_state = LEVEL::VICTORY;
        }
        return pair;
    }

    return {x, y};
}

#define B(a)  a > 30 ?  30 : a
#define A(b)  b < 0 ?  0 : b

std::pair<int, int> Nibbler::Level::circleScan(int r, int x, int y)
{
    int checks = 8;

    for (int _r = 1; _r <= r; _r++) {
        for (int check = 0; check < checks; check++) {
            if (this->isTileEmpty(B(x + _r), B(y + _r)))
                return {B(x + _r), B(y + _r)};
            if (this->isTileEmpty(B(x + _r), y))
                return {B(x + _r), y};
            if (this->isTileEmpty(B(x + _r), A(y - _r)))
                return {B(x + _r), A(y - _r)};
            if (this->isTileEmpty(x, B(y + _r)))
                return {x, B(y + _r)};
            if (this->isTileEmpty(x, A(y - _r)))
                return {x, A(y - _r)};
            if (this->isTileEmpty(A(x - _r), B(y + _r)))
                return {A(x - _r), B(y + _r)};
            if (this->isTileEmpty(A(x - _r), y))
                return {A(x - _r), y};
            if (this->isTileEmpty(A(x - _r), A(y - _r)))
                return {A(x - _r), A(y - _r)};
        }
        checks += 8;
    }
    return {x, y};
}

int Nibbler::Level::getScore() const
{
    return this->_score;
}
