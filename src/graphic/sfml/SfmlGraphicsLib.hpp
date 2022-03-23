/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "IGraphicsLib.hpp"

class SfmlGraphicsLib : public virtual IGraphicsLib
{
    public:
    // Constructor
    SfmlGraphicsLib();

    //config / view setup

    void loadConfig(void);




    //Runtime methods
    void drawTile(int tile_index, int x, int y) const override;


    private:
        gfx_config_t _config;




};
