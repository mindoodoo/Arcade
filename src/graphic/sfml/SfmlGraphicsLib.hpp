/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_ARCADE_NICOLAS_LATTEMANN_GRAPHICSLIB_HPP
#define B_OOP_400_BER_4_1_ARCADE_NICOLAS_LATTEMANN_GRAPHICSLIB_HPP

#include "../IGraphicsLib.hpp"

class SfmlGraphicsLib : public virtual IGraphicsLib
{
    public:
        SfmlGraphicsLib() = default;

        void hello() override;
};



#endif //B_OOP_400_BER_4_1_ARCADE_NICOLAS_LATTEMANN_GRAPHICSLIB_HPP
