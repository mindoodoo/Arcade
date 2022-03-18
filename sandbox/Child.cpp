/*
** EPITECH PROJECT, 2022
** Child.cpp
** File description:
** .
*/

#include "Child.hpp"

Child::Child()
{
}

Child::~Child()
{
}

void Child::hello() const
{
    std::cout << "Hello!" << std::endl;
}

extern "C"
{
    Interface *make()
    {
        std::cout << "YEYEYE" << std::endl;
        return new Child();
    }
}
