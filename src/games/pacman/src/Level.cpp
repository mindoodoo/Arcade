/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "Level.hpp"

Pacman::Level::Level(IGraphicsLib **gfx, gfx_config_t levelConf)
{
    this->_score = 0;
    this->_gfx = gfx;

    this->_levelConf = std::move(levelConf);

    this->_scene = new Terrain(gfx);
    this->_pacman = new Player(11, 13, this->_scene, gfx);
    this->_ghosts = new GhostManager(this->_scene, this->_gfx, this->_pacman);
    this->_ghostMovementTime = std::chrono::system_clock::now();
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
        }
    }

    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_ghostMovementTime).count() >= 250) {
        this->_ghosts->move(this->_pacman->getX(), this->_pacman->getY());
        this->_ghostMovementTime = now;
    }

    this->_pacman->move();
    if (this->_scene->getMap()[this->_pacman->getY()][this->_pacman->getX()].tile == PACGUM) {
        this->_score++;
        this->_scene->setTile(this->_pacman->getX(), this->_pacman->getY(), TERRAIN_FLOOR);
    } else if (this->_scene->getMap()[this->_pacman->getY()][this->_pacman->getX()].tile == BASICALLY_COCAINE) {

    }

    if (this->_ghosts->checkCollision(this->_pacman->getX(), this->_pacman->getY()))
        return LEVEL::DEFEAT;

    this->_scene->draw();
    this->_pacman->draw();
    this->_ghosts->draw();

    return LEVEL::RUNNING;
}

int Pacman::Level::getScore() const
{
    return this->_score;
}
