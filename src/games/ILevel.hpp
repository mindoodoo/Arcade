/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

class ILevel {
    public:
        virtual ~ILevel() = default;

        virtual int frame() = 0;

        virtual int getScore() const = 0;

};
