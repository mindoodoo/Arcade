/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#define PACMAN_PACGUM 1
#define PACMAN_HEAD 2
#define TERRAIN_WALL 3
#define TERRAIN_FLOOR 4

void mockDrawTile(int tile, int x, int y);

void mockInitGfxLib();

void mockShowText(const std::string &text, int x, int y);
