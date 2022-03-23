/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

class IGameManager {
    public:
        ~IGameManager() = default;

        virtual int frame() = 0;

        virtual int getScore() const = 0;

};
