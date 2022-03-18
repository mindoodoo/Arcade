/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_ARCADE_NICOLAS_LATTEMANN_NCURSESGRAPHICSLIB_HPP
#define B_OOP_400_BER_4_1_ARCADE_NICOLAS_LATTEMANN_NCURSESGRAPHICSLIB_HPP

#include "../IGraphicsLib.hpp"
#include <curses.h>

class NcursesGraphicsLib : virtual public IGraphicsLib
{
    public:
        NcursesGraphicsLib();

        ~NcursesGraphicsLib() override;

        void display() override;

        void flush() override;

        void showText(const std::string &text, int x, int y) override;

        void drawTile(int x, int y, int h, int w, char c) override;

        void drawTile(const std::string &path, int x, int y, int h, int w) override;

        void event() override;
};

#endif //B_OOP_400_BER_4_1_ARCADE_NICOLAS_LATTEMANN_NCURSESGRAPHICSLIB_HPP
