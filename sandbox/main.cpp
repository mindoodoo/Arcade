/*
** EPITECH PROJECT, 2022
** main.cpp
** File description:
** .
*/

#include "Interface.hpp"
#include "LdLoader.hpp"

int main(int ac, char **av)
{
    LDLoader<Interface> loader;

    loader.loadLib("./test.so");
    Interface *instance = loader.getInstance();
    if (instance)
        instance->hello();
}

// template class LDLoader<Interface>;