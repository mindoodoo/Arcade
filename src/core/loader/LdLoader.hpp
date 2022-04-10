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

template<class T>
class LDLoader
{
    public:
        LDLoader() = default;

        ~LDLoader();

        T *getInstance();

        void loadLib(const std::string &libpath);

        void closeLoadedLib();

        /**
         * encapsulation for dlopen
         * throws dlerror() if return value is null
         * @param path path to dynamic library
         * @return handle opened by dlopen
         */
        static void *open(const std::string &path);

        /**
         * encapsulation for dlsym
         * throws dlerror() if return value is null
         * @param handle pointer opened by dlopen
         * @param name name of the symbol
         * @return pointer to the symbol value
         */
        static void *getSymbol(void *handle, const std::string &name);

        /**
         * encapsulation for dlclose
         * returns 84 if input is a null pointer
         * @param handle pointer opened by dlopen
         * @return 0 if success, something else on error
         */
        static int close(void *handle);

        void clear();

        int getId();

    private:
        T *(*_lib_factory)();

        void *_handle = nullptr;

        int _id = 0;
};
