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
    gfx_config_t mockConfig = {"", "Trollface_non-free.png", "BADABB__.TTF", 347 / 2, 288 / 2, 4, 4}; //this is a mock tool for the mock function
    int a = 15;
    std::queue<char> que;
    std::string queualias = "LOL";
    
    while (1) {
        GraphLibSFML.checkConfig(mockConfig);
        GraphLibSFML.recordInputs();    


        // que = GraphLibSFML.getInput();
        // sf::CircleShape shape(a);
        // if (que.size() != 0)
        //     queualias = que.back();
        GraphLibSFML.flush();
        GraphLibSFML.drawTile(0, 0, 0);
        GraphLibSFML.drawTile(1, 1, 0);
        GraphLibSFML.drawTile(2, 0, 1);
        // GraphLibSFML.drawTile(3, 1, 1);
        // // GraphLibSFML.window.draw(shape);
        // GraphLibSFML.drawText(queualias, 0, 1);
        // GraphLibSFML.drawText("queualias", 0, 2);
        GraphLibSFML.display();
        // if (que.size() != 0)
        //     GraphLibSFML.popInput();
        // std::cout << a << std::endl;
        // a++;
    }
    return 0;
}