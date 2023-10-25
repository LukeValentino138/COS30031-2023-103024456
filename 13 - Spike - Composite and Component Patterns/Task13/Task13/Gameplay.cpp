#include "Gameplay.h"
#include "CommandManager.h"
#include <iostream>

std::string Gameplay::getMapFilePath() const
{
    return mapFilePath;
}

StateType Gameplay::getStateType() const {
    return StateType::Gameplay;
}

void Gameplay::update() {
    std::string input;
    std::cout << "> ";
    std::getline(std::cin, input);
    cmdManager->processInput(input);
}

void Gameplay::render() {

}

Gameplay::Gameplay(GameManager* manager, const std::string& filepath)
    : _manager(manager)
{
    cmdManager = new CommandManager(this);  

    int initialPlayerHealth = 100;  
    world.loadPlayer(&player, initialPlayerHealth); 

    world.load_map(filepath, getPlayer()); 

    world.print();

    Vertex* initialLocation = this->world.vertices["Bus Depot"];
    player.setCurrentLocation(initialLocation);
}


Gameplay::~Gameplay() {
    delete cmdManager;
}