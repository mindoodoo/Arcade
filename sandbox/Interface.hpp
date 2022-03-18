/*
** EPITECH PROJECT, 2022
** Interface.hpp
** File description:
** .
*/

#pragma once

class Interface {
    public:
        ~Interface() = default;
        virtual void hello() const = 0;

    protected:
};
