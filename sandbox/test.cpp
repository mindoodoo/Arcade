/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <string>

void *make(void)
{
    return new std::string("Hello");
}

struct export_vtable
{
    void *(*make)(void);
};

struct export_vtable exports = {.make =  make};
