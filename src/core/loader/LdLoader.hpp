/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#pragma once

#include <string>
#include <dlfcn.h>
#include <iostream>
#include "IGameLib.hpp"
#include "IGraphicsLib.hpp"

// typedef IGraphicsLib *(*entry)();

template <class T>
class LDLoader {
    public:
        LDLoader() = default;
        ~LDLoader();

        T *getInstance();
        void loadLib(std::string libpath);

    private:
        T *(*_lib_factory)();
        void *_handle;
};
