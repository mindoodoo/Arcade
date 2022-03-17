/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <iostream>
#include "../graphic/LdLoader.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Please provide a graphics library." << std::endl;
        return 84;
    }

    auto x = new LDLoader(argv[1]);
    return 0;
}
