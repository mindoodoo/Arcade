/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/


#include "BaseGhost.hpp"

void Pacman::BaseGhost::setState(Pacman::GhostState state)
{
    this->_state = state;
    this->stateChangeTimer;
}
