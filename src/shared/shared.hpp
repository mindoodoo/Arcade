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

std::vector<std::vector<std::string>> csvToTable(const std::string &filepath);
std::vector<std::string> csvToVector(const std::string &filepath);
