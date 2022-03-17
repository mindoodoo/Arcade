/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <dlfcn.h>
#include "LdLoader.hpp"

LDLoader::LDLoader(const std::string &path)
{
    this->dyn_lib = dlopen(path.c_str(), RTLD_NOW);

    auto *table = static_cast<export_vtable *>(dlsym(this->dyn_lib, "exports"));

    make = table->make;
    auto e = make();
    e->hello();
}

LDLoader::~LDLoader()
{
    dlclose(this->dyn_lib);
}
