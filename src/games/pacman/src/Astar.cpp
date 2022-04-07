/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Description
*/

#include <algorithm>
#include <valarray>
#include <iostream>
#include <stack>
#include "Astar.hpp"
#include "../include/PacmanMacros.hpp"

#define RANGE(a) a.begin(), a.end()

void reverseQueue(std::queue<coordinates_t> &Queue)
{
    std::stack<coordinates_t> Stack;
    while (!Queue.empty()) {
        Stack.push(Queue.front());
        Queue.pop();
    }
    while (!Stack.empty()) {
        Queue.push(Stack.top());
        Stack.pop();
    }
}

std::deque<coordinates_t> returnPath(Node currentNode)
{
    std::deque<coordinates_t> path;

    while (true) {
        std::cout << "help " << currentNode.g << " " << currentNode.position.first << " " << currentNode.position.second
                  << std::endl;
        path.push_back(currentNode.position);
        if (currentNode.parent == nullptr || currentNode == *currentNode.parent)
            break;
        currentNode = *currentNode.parent;
    }

    return path;
}

std::deque<coordinates_t> calculateAStar(coordinates_t start, coordinates_t end, map_t map)
{
    Node startNode = Node(nullptr, start);
    Node endNode = Node(nullptr, end);

    std::deque<Node> openList;
    std::deque<Node> closedList;

    openList.push_back(startNode);

    int outerIterations = 0;
    size_t max_iterations = map[0].size() * map.size();

    std::deque<std::pair<int, int>> adjacentSquares;
    adjacentSquares.push_front({0, -1});
    adjacentSquares.push_front({0, 1});
    adjacentSquares.push_front({-1, 0});
    adjacentSquares.push_front({1, 0});

    while (!openList.empty()) {
        outerIterations += 1;

        // Get the current node
        Node currNode = openList.front();
        openList.pop_front();
        closedList.push_back(currNode);

        if (outerIterations > max_iterations) {
            // if we hit this point return the path such as it is
            // it will not contain the destination

            std::cerr << "giving up on pathfinding too many iterations" << std::endl;
            return returnPath(currNode);
        }

        // Found the goal
        if (currNode == endNode) {
            std::cerr << "AT GOAL" << std::endl;

            return returnPath(currNode);
        }

        // Generate children
        std::deque<Node> children;
        std::cout << currNode.position.first << " " << currNode.position.second << std::endl;
        for (std::pair<int, int> posOffset: adjacentSquares) {
            // Adjacent squares

            // Get node position
            coordinates_t nodePosition = {currNode.position.first + posOffset.first,
                                          currNode.position.second + posOffset.second};

            // Make sure within range
            if (nodePosition.first > (map.size() - 1)
                || (nodePosition.first < 0)
                || nodePosition.second > (map[map.size() - 1].size() - 1)
                || nodePosition.second < 0) {
                std::cerr << "not within range" << std::endl;
                continue;
            }

            // Make sure walkable terrain
            if (map[nodePosition.first][nodePosition.second].tile == TERRAIN_WALL) {
                std::cerr << "is wall" << std::endl;
                continue;
            }

            // Create new node
            Node newNode = Node(&currNode, nodePosition);

            children.push_back(newNode);
        }

        for (Node child: children) {

            if (std::find(RANGE(closedList), child) != closedList.end()) {
                std::cerr << child.position.first << " " << child.position.second << " in closed list" << std::endl;
                continue;
            }

            child.g = currNode.g + 1;
            child.h = std::pow((child.position.first - endNode.position.first), 2) +
                      std::pow((child.position.second - endNode.position.second), 2);
            child.f = child.g + child.h;

            int check = 0;
            for (auto openNode: openList) {
                if (child == openNode && child.g > openNode.g)
                    check++;
            }
            if (check > 0) {
                std::cerr << "check above 0" << std::endl;
                continue;
            }

            openList.push_back(child);
        }
    }
    std::cerr << "Couldn't get a path to destination" << std::endl;
    return {};
}

Node::Node(Node *parent, coordinates_t position)
{
    this->position = position;
    this->parent = parent;
    this->g = 0;
    this->f = 0;
    this->h = 0;
}

bool Node::operator==(Node other) const
{
    return this->position.first == other.position.first && this->position.second == other.position.second;
}
