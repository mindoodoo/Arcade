/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include "Sdl2GraphicsLib.hpp"

Sdl2GraphicsLib::Sdl2GraphicsLib()
{
    this->_config = {
        "",
        "",
        "",
        0,
        0,
        0,
        0
    };
}

Sdl2GraphicsLib::~Sdl2GraphicsLib()
{
    
}

std::queue<char> &Sdl2GraphicsLib::getInput()
{
    return this->_inputQueue;
}

void Sdl2GraphicsLib::popInput()
{
    this->_inputQueue.pop();
}

void Sdl2GraphicsLib::recordInputs()
{

}

void Sdl2GraphicsLib::display()
{

}

void Sdl2GraphicsLib::flush() 
{

}

void Sdl2GraphicsLib::checkConfig(const gfx_config_t &config)
{
    // Check if config is same
    if (config != this->_config) {
        this->_config = config;
        this->loadConfig();
    }
}

void Sdl2GraphicsLib::loadConfig(void)
{
   
}

