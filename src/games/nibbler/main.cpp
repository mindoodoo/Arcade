/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <ncurses.h>
#include "src/Core.hpp"

int main()
{
    auto *core = new Core();

    while (true) {
        core->frame();
        refresh();
    }
}
