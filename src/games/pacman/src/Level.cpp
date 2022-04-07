/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "Level.hpp"
#include "../../BaseGameCore.hpp"

Pacman::Level::Level(IGraphicsLib **gfx, gfx_config_t levelConf)
{
    this->_score = 0;
    this->_gfx = gfx;

    this->_levelConf = std::move(levelConf);

    this->_scene = new Terrain(gfx);
    this->_ghost = new BaseGhost(this->_scene, this->_gfx);
    this->_pacman = new Player(this->_scene->getHeight() / 2, this->_scene->getWidth() / 2, this->_scene, gfx);
}

int Pacman::Level::frame()
{
    GFX->checkConfig(this->_levelConf);

    std::queue<char> inputs = GFX->getInput();

    this->_score++;
    if (!inputs.empty()) {
        char c = inputs.back();

        switch (c) {
            case 'z':
            case 'w':
                this->_pacman->move(0, -1);
                GFX->popInput();
                break;
            case 's':
                this->_pacman->move(0, 1);
                GFX->popInput();
                break;
            case 'q':
            case 'a':
                this->_pacman->move(-1, 0);
                GFX->popInput();
                break;
            case 'd':
                this->_pacman->move(1, 0);
                GFX->popInput();
                break;
        }
    }

    this->_ghost->move(this->_pacman->getX() - 2, this->_pacman->getY());
    this->_scene->draw();
    this->_pacman->draw();
    this->_ghost->draw();

    return LEVEL::RUNNING;
}

int Pacman::Level::getScore() const
{
    return this->_score;
}
