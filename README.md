# Arcade

This project aims to implement a **set of basic arcade games** following particular implementation instructions. The main goal was to have create **game and graphical** library interfaces in order to be able to switch games or graphical environments at runtime.

This project was a group project during my **second year at Epitech** and was implemented over **a month** long period.

## Features

### Gameplay Features

- Persistent Scoreboard
- **Nibbler** implementation
- **Pacman** implementation
    - Following original implementation, our implementation implements **a different AI algorithm for each ghost.**
    - Multiple levels
- **Both games,** implement **tiling based level parsing** enabling us to use [tiled](https://www.mapeditor.org/) in order to create our levels **quickly and easily**.

### Architectural Features

- **Graphical library switch at runtime, with no effect on gameplay**
    - **Including** between gui libraries *(sdl2 or sfml)* and terminal mode *(ncurses)*
- Game loading at runtime
- Levels parsed at runtime (no need to restart game to refresh levels)
- **Graphical Library** and **Game Library** interfaces
    - Allows for an **easy implementation of additional games or graphical libraries**

## Building

**Before building,** please make sure you have the following packages installed :

```
ncurses
sfml
sdl2
sdl2_image
sdl2_ttf
```

The build process is split up accross **multiple** dynamic libraries, and one binary :

- **Game Libraries**
    - arcade_nibbler.so
    - arcade_pacman.so
- **Graphical Libary Encapsulations**
    - arcade_sfml.so
    - arcade_sdl2.so
    - arcade_ncurses.so

These binaries can be built using ```make```.

## Usage

In order to first run the ```arcade``` program, you need to specify a graphical library encapsulation for it to start the menu in. You will then be able to **switch at runtime** however, you **must pick one to start up in.**

Such as :

```
./arcade <graphical library>
```

The available graphical libraries are stated in the building section of this document.
