/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <string>

class IGraphicsLib
{
    public:
        virtual ~IGraphicsLib() = default;

        virtual void display() = 0;

        virtual void drawTile(int x, int y, int tile) = 0;
        // Note : Could add possibility for rotation of tile in the future
        // if needed
};
