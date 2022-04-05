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
    this->_name = NAME;
    this->_renderer = NULL;
    this->_textTexture = NULL;
    this->_tilesetTexture = NULL;
    this->_font = NULL;
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);
}

Sdl2GraphicsLib::~Sdl2GraphicsLib()
{
    TTF_CloseFont(this->_font);
    SDL_DestroyTexture(this->_textTexture);
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
    TTF_Quit();
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
    //window creation and stuff
    std::cout << "Window dimensions are : " << this->_config.windowWidth * this->_config.tileWidth <<
    ":" << this->_config.windowHeight * this->_config.tileHeight << std::endl;

    //SDL_CreateWindowAndRenderer( this->_config.windowWidth * this->_config.tileWidth, this->_config.windowHeight * this->_config.tileHeight, SDL_WINDOW_RESIZABLE, &this->_window, &this->_renderer);
    
    if (this->_window)
        SDL_DestroyWindow(this->_window);
    this->_window = SDL_CreateWindow("GAME", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
    this->_config.windowWidth * this->_config.tileWidth,
    this->_config.windowHeight * this->_config.tileHeight, SDL_WINDOW_SHOWN);

    if (this->_renderer)
        SDL_DestroyRenderer(this->_renderer);
    this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
    
    //font loading
    this->_font = TTF_OpenFont(this->_config.fontFolderPath.c_str(), this->_config.tileWidth);
    if (this->_font == NULL)
        std::cout << "failed loading font" << std::endl;
    
    //tileset loading
    this->loadTileset();
}

void Sdl2GraphicsLib::loadTileset()
{
    SDL_Texture *newTexture;
    SDL_Rect tileRect = {0, 0, this->_config.tileWidth,
    this->_config.tileHeight};

    int x;
    int y;

    if (this->_config.graphicalTilesetPath == "")
        return;

    this->_tilesetSurface = IMG_Load(this->_config.graphicalTilesetPath.c_str());

    if (!this->_tilesetSurface)
        std::cout << "ERROR LOADING TILESET IMAGE" << std::endl;
        // Potentially throw error here
    else {
        this->_tilesetTexture = SDL_CreateTextureFromSurface(this->_renderer, this->_tilesetSurface);

        // Get tileset width and height in tiles
        x = this->_tilesetSurface->w / this->_config.tileWidth;
        y = this->_tilesetSurface->h / this->_config.tileHeight;
        
        SDL_FreeSurface(this->_tilesetSurface);
        
        for (int i = 0; i < y; i++){ 
            for (int j = 0; j < x; j++) {
                // Update targeted part of the image
                tileRect.x = j * this->_config.tileWidth;
                tileRect.y = i * this->_config.tileHeight;

                // Load tile texture, apply to texture and push to vector
                newTexture = SDL_CreateTexture(this->_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,
                tileRect.w, tileRect.h);

                SDL_SetRenderTarget(this->_renderer, newTexture);
                SDL_RenderCopy(this->_renderer, this->_tilesetTexture, &tileRect, NULL);
                SDL_SetRenderTarget(this->_renderer, NULL);
                this->_tiles.push_back(newTexture);
            }
        }
    }   
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
    char pressedKey;

	SDL_Event event;
	// Events management
	while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            this->_inputQueue.push('q');
        }
        else if (event.type == SDL_KEYDOWN) {
            pressedKey = event.key.keysym.sym;
			this->_inputQueue.push(pressedKey);
        }   
	}
}

void Sdl2GraphicsLib::display()
{
    SDL_RenderPresent(this->_renderer);
}

void Sdl2GraphicsLib::flush() 
{
    SDL_RenderClear(this->_renderer);
}

void Sdl2GraphicsLib::drawTile(int tile_index, int x, int y)
{

	SDL_Rect dest = {x *  this->_config.tileWidth , y *  this->_config.tileHeight,
    this->_config.tileWidth, this->_config.tileHeight};
    SDL_RenderCopy(this->_renderer, this->_tiles[tile_index], NULL, &dest);

}

void Sdl2GraphicsLib::drawText(const std::string &txt, int x, int y)
{
    SDL_Rect textLocation = {x * this->_config.tileWidth , y * this->_config.tileHeight, 0, 0};
    SDL_Color color = {255, 255, 255, 42};

    this->_textSurface = TTF_RenderText_Solid(this->_font, txt.c_str(), color);
    this->_textTexture = SDL_CreateTextureFromSurface(this->_renderer, this->_textSurface);

    textLocation.w = this->_textSurface->w;
    textLocation.h = this->_textSurface->h;

    SDL_RenderCopy(this->_renderer, this->_textTexture, NULL, &textLocation);    
    SDL_FreeSurface(this->_textSurface);
}

std::string Sdl2GraphicsLib::getName()
{
    return this->_name;
}




