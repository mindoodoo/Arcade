/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <dlfcn.h>
#include <iostream>

struct export_vtable
{
    void (*make)();
};

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Please provide a graphics library." << std::endl;
        return 84;
    }

    void *p;
    struct export_vtable *imports;

    if ((p = dlopen(argv[1], RTLD_NOW)) == nullptr)
        return 84;

    imports = static_cast<export_vtable *>(dlsym(p, "exports"));

    imports->make();
    return 0;
}
