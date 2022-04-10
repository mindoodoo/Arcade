/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <fstream>
#include "Level.hpp"

Pacman::Level::Level(IGraphicsLib **gfx, size_t level)
{
    this->_score = 0;
    this->_gfx = gfx;

    this->_levelConf = parseGfx(CONFIG_PATH, level);

    this->_scene = new Terrain(this->_levelConf.mapPath, gfx);

    this->_pacman = new Player(11, 13, this->_scene, gfx);
    this->_ghosts = new GhostManager(this->_scene, this->_gfx, this->_pacman, &this->_score);
    this->_state = LEVEL::RUNNING;

    this->cocainePillsCount = this->_scene->tileCount(BASICALLY_COCAINE);
}

int Pacman::Level::frame()
{
    GFX->checkConfig(this->_levelConf);

    std::queue<char> inputs = GFX->getInput();

    if (!inputs.empty()) {
        char c = inputs.back();
        switch (c) {
            case 'z':
            case 'w':
                this->_pacman->turn(0, -1);
                GFX->popInput();
                break;
            case 's':
                this->_pacman->turn(0, 1);
                GFX->popInput();
                break;
            case 'q':
            case 'a':
                this->_pacman->turn(-1, 0);
                GFX->popInput();
                break;
            case 'd':
                this->_pacman->turn(1, 0);
                GFX->popInput();
                break;
            default:
                break;
        }
    }

    this->_ghosts->move();
    this->_pacman->move();

    if (this->_ghosts->checkCollision())
        this->_state = LEVEL::DEFEAT;

    this->checkItemCollision();

    this->_scene->draw();
    this->_ghosts->draw();
    this->_pacman->draw();

    return this->_state;
}

int Pacman::Level::getScore() const
{
    return this->_score;
}

void Pacman::Level::checkItemCollision()
{
    size_t pacmanX = this->_pacman->getX();
    size_t pacmanY = this->_pacman->getY();
    map_t map = this->_scene->getMap();

    if (map[pacmanY][pacmanX].tile == PACGUM) {
        this->_score++;
        this->_scene->setTile(pacmanX, pacmanY, TERRAIN_FLOOR);
    } else if (map[pacmanY][pacmanX].tile == BASICALLY_COCAINE) {
        this->_score += 10;
        this->cocainePillsCount--;
        this->_pacman->setState(Player::State::SUPER);
        this->_ghosts->makeVulnerable();
        this->_scene->setTile(pacmanX, pacmanY, TERRAIN_FLOOR);
        if (this->cocainePillsCount <= 0) {
            this->saveScore();
            this->_state = LEVEL::VICTORY;
        }
    }
}

void Pacman::Level::saveScore() const
{
    std::fstream file("./assets/pacman/scoreboard", std::ios::app);

    if (file.tellg() > 0)
        file << ",";
    file << std::to_string(this->_score);
    file.close();
}
