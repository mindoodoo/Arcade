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
#include <filesystem>

template <class T>
class LDLoader {
    public:
        LDLoader() = default;

        ~LDLoader();

        T *getInstance();

        void loadLib(const std::string &libpath);

    private:
        T *(*_lib_factory)();
        void *_handle = nullptr;
};
