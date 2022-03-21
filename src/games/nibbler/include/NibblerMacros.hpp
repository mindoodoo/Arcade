/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#define NIBBLER_HEAD 0
#define NIBBLER_BODY 1
#define NIBBLER_TAIL 2

#define ITEM_FRUIT 10
#define ITEM_AXE 11

#define TERRAIN_WALL 20
#define TERRAIN_FLOOR 21



#include <string>
void mockDrawTile(int tile, int x, int y);

void mockInitGfxLib();

void mockShowText(const std::string &text, int x, int y);
