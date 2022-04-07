/*
** EPITECH PROJECT, 2022
** shared.hpp
** File description:
** .
*/

#pragma once

#include <vector>
#include <string>

#define GAME_ID 48
#define GFX_iD 93

typedef struct
{
    int tile;
    int orientation;
} gfx_tile_t;

std::vector<std::vector<std::string>> csvToTable(const std::string &filepath);

std::vector<std::string> csvToVector(const std::string &filepath);

std::vector<std::string> splitStr(std::string str, std::string sep);

std::vector<std::vector<gfx_tile_t>> parseMap(const std::string &path);

std::vector<std::vector<gfx_tile_t>> parseMap(const std::string &path);
