/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once
#include "chrono"

namespace Pacman
{
    enum GhostState
    {
        HUNTING = 0,
        HUNTED = 1,
        DEFEATED = 2,
        RECOVERING = 3,
        SLEEPING = 0
    };

    class BaseGhost
    {
        public:
            BaseGhost();

            virtual void move() = 0;

            void setState(GhostState state);
        protected:
            GhostState _state;

            int stateChangeTimer;
    };
}
