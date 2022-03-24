/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** tesmain
*/


#include "SfmlGraphicsLib.hpp"
#include <iostream>

int main()
{
    SfmlGraphicsLib GraphLibSFML;
    int a = 15;
    std::queue<char> que;
    while (GraphLibSFML.window.isOpen()) {
        que = GraphLibSFML.getInput();
        sf::CircleShape shape(a);
        GraphLibSFML.flush();
        GraphLibSFML.window.draw(shape);
        GraphLibSFML.display();
        std::cout << a << std::endl;
        a++;
    }
    
    
  
    
    return 0;
}