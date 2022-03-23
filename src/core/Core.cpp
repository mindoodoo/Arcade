/*
** EPITECH PROJECT, 2022
** Core.cpp
** File description:
** .
*/

#include "Core.hpp"

Core::Core()
{
    // THIS IS HARDCODED AND WILL CHANGE
    // Load libraries
    this->_gfxLoader.loadLib("./lib/ncurseslib.so");
    this->_gameLoader.loadLib("./lib/arcade_nibbler.so");

    // Get instances of game and gfx libraries
    this->_gfxPtr = this->_gfxLoader.getInstance();
    this->_gamePtr = this->_gameLoader.getInstance();

    // Set game ptr
    this->_gamePtr->setGfx(&this->_gfxPtr);
}

Core::~Core()
{
    if (this->_gamePtr)
        delete this->_gamePtr;
    if (this->_gfxPtr)
        delete this->_gfxPtr;
}

void Core::mainLoop(void)
{
    while(true) {
        this->_gamePtr->frame();
    }
}
