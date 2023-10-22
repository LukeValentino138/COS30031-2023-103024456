#include "Gameplay.h"
#include <iostream>
Gameplay::Gameplay(GameManager* manager) : _manager(manager), cmdManager(manager) {

    Vertex* initialLocation = _manager->world.vertices["Bus Depot"]; 
    _manager->getPlayer()->setCurrentLocation(initialLocation);
}

StateType Gameplay::getStateType() const {
    return StateType::Gameplay;
}

void Gameplay::update() {
    std::string input;
    std::cout << "> ";
    std::getline(std::cin, input);
    cmdManager.processInput(input);
}

void Gameplay::render() {

}
