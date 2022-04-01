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
    SDL_DestroyTexture(this->_texture);
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
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
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf("error initializing SDL: %s\n", SDL_GetError());
    this->_window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->_config.windowWidth, this->_config.windowHeight, SDL_WINDOW_SHOWN);
    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
    this->_surface = IMG_Load("index.jpeg");
    this->_font = TTF_OpenFont("BADABB__.TTF", this->_config.tileWidth);
    this->_texture = SDL_CreateTextureFromSurface(this->_renderer, this->_surface);
   
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
    int close = 0;
    while (!close) {
		SDL_Event event;

		// Events management
		while (SDL_PollEvent(&event)) {
			switch (event.type) {

			case SDL_QUIT:
				// handling of close button
				close = 1;
				break;

			case SDL_KEYDOWN:
				// keyboard API for key pressed
				switch (event.key.keysym.scancode) {
				case SDL_SCANCODE_W:
				case SDL_SCANCODE_UP:
                    this->_inputQueue.push('w');
					break;
				case SDL_SCANCODE_A:
				case SDL_SCANCODE_LEFT:
                    this->_inputQueue.push('a');
					break;
				case SDL_SCANCODE_S:
				case SDL_SCANCODE_DOWN:
                    this->_inputQueue.push('s');
					break;
				case SDL_SCANCODE_D:
				case SDL_SCANCODE_RIGHT:
                    this->_inputQueue.push('d');
					break;
				default:
					break;
				}
			}
		}
    }

}

void Sdl2GraphicsLib::display()
{

}

void Sdl2GraphicsLib::flush() 
{

}



