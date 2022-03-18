/*
** EPITECH PROJECT, 2022
** Child.hpp
** File description:
** Child
*/

#pragma once

#include <iostream>
#include "Interface.hpp"

class Child: public virtual Interface {
    public:
        Child();
        ~Child();

        void hello() const;

    private:
};

extern "C"
{
    Interface *make();
}
