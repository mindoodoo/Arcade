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

        virtual void flush() = 0;

        virtual void showText(const std::string &text, int x, int y) = 0;

        virtual void drawTile(int x, int y, int h, int w, char c) = 0;

        virtual void drawTile(const std::string &text, int x, int y, int h, int w) = 0;

        virtual void event() = 0;
};
