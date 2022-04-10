/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <iostream>
#include "Core.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Please provide a graphics library." << std::endl;
        return 84;
    }

    Core *coreInstance = new Core(argv[1]);
    coreInstance->mainLoop();


//     delete coreInstance;

    return 0;
}
