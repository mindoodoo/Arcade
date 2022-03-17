/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#ifndef B_OOP_400_BER_4_1_ARCADE_NICOLAS_LATTEMANN_LDLOADER_HPP
#define B_OOP_400_BER_4_1_ARCADE_NICOLAS_LATTEMANN_LDLOADER_HPP

#include <string>
#include "IGraphicsLib.hpp"

typedef IGraphicsLib *(*entry)();

struct export_vtable {
    entry make;
};

class LDLoader {
        void *dyn_lib;
    public:
        explicit LDLoader(const std::string &path);
        ~LDLoader();
        entry make;
};

#endif //B_OOP_400_BER_4_1_ARCADE_NICOLAS_LATTEMANN_LDLOADER_HPP
