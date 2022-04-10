/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/


#include "Level.hpp"
#include "MegaFruit.hpp"

Nibbler::Level::Level(IGraphicsLib **gfx, size_t level)
{
    this->_score = 0;
    this->_levelConf = parseGfx(CONFIG_PATH, level);

    this->_scene = new Terrain(this->_levelConf.mapPath, gfx);
    std::pair<int, int> dimensions = this->_scene->getMapDimensions();

    this->_gameHeight = dimensions.second;
    this->_gameWidth = dimensions.first;

    this->_levelConf.windowWidth = this->_gameWidth;
    this->_levelConf.windowHeight = this->_gameHeight;

    this->_nibbler = new Player(this->_gameWidth / 2, this->_gameHeight / 2, this->_scene, gfx);

    this->_gfx = gfx;

    this->_state = LEVEL::RUNNING;

    this->generateItems(ITEM_FRUIT1, this->_gameHeight * this->_gameWidth * 0.05);
    this->generateItems(ITEM_FRUIT2, this->_gameHeight * this->_gameWidth * 0.02);
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
        this->_state = this->_score >= 200 ? LEVEL::VICTORY : LEVEL::DEFEAT;

    this->checkItemCollision();
    this->draw();
    return this->_state;
}

void Nibbler::Level::checkItemCollision()
{
    const segment_t head = this->_nibbler->head();

    for (Item *item: this->_items) {
        if (item->itemCollision(head.x, head.y)) {
            item->effect(this->_nibbler, &this->_score);
            std::pair<int, int> coords = this->randomLocation();
            item->relocate(coords.first, coords.second);
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
            case ITEM_FRUIT1:
                item = new Fruit(coords.first, coords.second, this->_gfx);
                break;
            case ITEM_FRUIT2:
                item = new MegaFruit(coords.first, coords.second, this->_gfx);
                break;
            default:
                break;
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
    size_t x;
    size_t y;

    srandom(std::chrono::system_clock::now().time_since_epoch().count());

    x = random() % (this->_gameWidth - 2) + 1;
    y = random() % (this->_gameHeight - 2) + 1;

    if (!this->isTileEmpty(x, y)) {
        std::pair<int, int> dim = this->_scene->getMapDimensions();
        std::pair<int, int> pair = circleScan(dim.first > dim.second ? dim.first : dim.second, x, y);

        if (pair.first == -1)
            this->_state = LEVEL::VICTORY;
        return pair;
    }

    return {x, y};
}

#define B(a)  a > r ?  r : a
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

Nibbler::Level::~Level()
{
    std::fstream file("./assets/nibbler/scoreboard", std::ios::app);

    if (file.tellg() > 0)
        file << ",";
    file << std::to_string(this->_score);
    file.close();
}
