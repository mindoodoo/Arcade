/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "../../../shared_interfaces/IGraphicsLib.hpp"
#include "Nibbler.hpp"

class GameManager
{
    public:
        //        GameManager(IGraphicsLib& gfxLib);
        GameManager(int map);

        ~GameManager() = default;

        int frame();

        void draw();

        void checkItemCollision();

        void generateItems(int item, size_t amount);

        bool isTileEmpty(int x, int y);

        std::pair<int, int> randomLocation();

        int getScore();
    private:
        Nibbler *_nibbler;
        Terrain *_scene;
        std::vector<Item *> _items;
        size_t _gameHeight;
        size_t _gameWidth;

        int _score;

        int _timeLeft;


};
