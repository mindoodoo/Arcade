/*
** EPITECH PROJECT, 2022
** GameCore.cpp
** File description:
** .
*/
#define NIBBLER_HEAD 0
#define NIBBLER_BODY 1
#define NIBBLER_TAIL 2

#define ITEM_FRUIT 10
#define ITEM_AXE 11

#define TERRAIN_WALL 20
#define TERRAIN_FLOOR 21

#include "Core.hpp"
#include "map"

Core::Core(const std::string &gfxPath)
{
    try {
        // THIS IS HARDCODED AND WILL CHANGE
        // Load libraries
        this->_gfxLoader.loadLib(gfxPath);

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
    while (this->_gamePtr->frame() == 0);
}

void Core::launchGame()
{
    this->_gameLoader.loadLib("./lib/arcade_nibbler.so");

    this->_gamePtr = this->_gameLoader.getInstance();

    this->_gamePtr->setGfx(&this->_gfx);
}
