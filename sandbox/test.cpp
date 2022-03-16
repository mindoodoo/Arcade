/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <stdio.h>

void prints(void)
{
    printf("Hello");
}

struct export_vtable {
    void (*prints)(void);
};

struct export_vtable exports = { prints };
