/*
** EPITECH PROJECT, 2022
** operators.cpp
** File description:
** .
*/

#include "IGraphicsLib.hpp"

bool operator==(gfx_config_t const &left, gfx_config_t const &right)
{
    if (left.tileWidth != right.tileWidth)
        return false;
    if (left.tileHeight != right.tileHeight)
        return false;
    if (left.windowHeight != right.windowHeight)
        return false;
    if (left.windowWidth != right.windowWidth)
        return false;
    if (left.asciiTilesetPath != right.asciiTilesetPath)
        return false;
    if (left.graphicalTilesetPath != right.graphicalTilesetPath)
        return false;
    if (left.fontFolderPath != right.fontFolderPath)
        return false;
    return true;
}

bool operator!=(gfx_config_t const &left, gfx_config_t const &right)
{
    return !(left == right);
}
