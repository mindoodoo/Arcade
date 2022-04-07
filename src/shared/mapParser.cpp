/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <vector>
#include <string>
#include "shared.hpp"
#include "IGraphicsLib.hpp"

std::vector<std::vector<gfx_tile_t>> parseMap(const std::string &path)
{
    std::vector<std::vector<std::string>> parsedCsv = csvToTable(path);
    std::vector<gfx_tile_t> tempRow;
    std::vector<std::string> splitCell;

    std::vector<std::vector<gfx_tile_t> > map;

    for (long unsigned int i = 0; i < parsedCsv.size(); i++) {
        tempRow.clear();

        for (long unsigned int j = 0; j < parsedCsv[i].size(); j++) {
            // Split tile from orientation
            splitCell = splitStr(parsedCsv[i][j], ";");

            // Push new gfx tile to row
            tempRow.push_back({
                stoi(splitCell[0]),
                (splitCell.size() > 1 ? stoi(splitCell[1]) : ORIENT_TOP)
            });
        }

        map.push_back(tempRow);
    }

    return map;
}
