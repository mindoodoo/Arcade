/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include "Terrain.hpp"
#include <algorithm>
#include <valarray>
#include <iostream>
#include <stack>
#include <cmath>

class Node
{
    public:
        Node(Node *parent, coordinates_t position);

        Node *parent;

        coordinates_t position;

        int g;
        int h;
        int f = 0;
};

std::deque<coordinates_t> calculateAStar(coordinates_t start, coordinates_t end, map_t map);

bool operator==(Node y, Node x);
