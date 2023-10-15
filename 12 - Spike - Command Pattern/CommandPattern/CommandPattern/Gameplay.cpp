#include "Gameplay.h"
#include <iostream>

Gameplay::Gameplay(GameManager* manager, const std::string& mapFilePath) {
    _manager = manager;
    graph.load_map(mapFilePath);
    currentLocation = "Bus Depot"; //hard coded for now, will eventually be from the json file
}

StateType Gameplay::getStateType() const {
    return StateType::Gameplay;
}

void Gameplay::update() {
    std::string command;
    std::cout << "Enter command (go [direction] or quit): ";
    std::cin >> command;

    if (command == "quit") {
        _manager->queuePop(1); 
    }
    else if (command == "go") {
        std::string direction;
        std::cin >> direction;

        bool found = false;
        for (const auto& dir : graph.vertices[currentLocation]->adj) {
            if (dir.first == direction) {
                currentLocation = dir.second->name;
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Invalid direction!" << std::endl;
        }
    }
    else {
        std::cout << "Invalid command!" << std::endl;
    }
}

void Gameplay::render() {
    std::cout << "You are at: " << currentLocation << std::endl;
    std::cout << "Available directions: ";
    for (const auto& dir : graph.vertices[currentLocation]->adj) {
        std::cout << dir.first << " ";
    }
    std::cout << std::endl;
}