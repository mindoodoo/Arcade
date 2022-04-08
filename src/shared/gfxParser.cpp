/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <iostream>
#include "IGraphicsLib.hpp"
#include "shared.hpp"

gfx_config_t parseGfx(const std::string &path, size_t index)
{

    std::vector<std::vector<std::string>> csv = csvToTable(path);

    if (index + 1 >= csv.size()) {
        std::cerr << "Graphics config index is out of bounds" << std::endl;
        return {};
    }

    std::vector<std::string> map = csv[index + 1];
    gfx_config_t config;

    config.asciiTilesetPath = map[0];
    config.graphicalTilesetPath = map[1];
    config.fontFolderPath = map[2];
    config.mapPath = map[3];
    config.tileWidth = std::stoi(map[4]);
    config.tileHeight = std::stoi(map[5]);
    config.windowWidth = std::stoi(map[6]);
    config.windowHeight = std::stoi(map[7]);
    config.scale = std::stoi(map[8]);

    return config;
}
