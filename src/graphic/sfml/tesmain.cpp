/*
** EPITECH PROJECT, 2022
** ARCADE
** File description:
** tesmain
*/


#include "SfmlGraphicsLib.hpp"
#include <iostream>
#include <fstream>
#include <iostream>


int main()
{
    SfmlGraphicsLib GraphLibSFML;
    std::vector<std::string> mockconfigs = {"", "mockgraphtileset.csv", "BADABB__.TTF", "16", "16", "50", "37,5"}; //this is a mock tool for the mock function
    GraphLibSFML.mocksetconfig(mockconfigs); //this is a mock function
    GraphLibSFML.loadConfig();
    int a = 15;
    std::queue<char> que;
    std::string queualias = "LOL";
    while (GraphLibSFML.window.isOpen()) {
        que = GraphLibSFML.getInput();
        sf::CircleShape shape(a);
        if (que.size() != 0)
            queualias = que.back();
        GraphLibSFML.flush();
        GraphLibSFML.window.draw(shape);
        GraphLibSFML.drawText(queualias, 250, 250);
        GraphLibSFML.display();
        if (que.size() != 0)
            GraphLibSFML.popInput();
        std::cout << a << std::endl;
        a++;
    }   
    return 0;
}