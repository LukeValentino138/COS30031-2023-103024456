#include "CommandPickUp.h"
#include <iostream>

CommandPickUp::CommandPickUp(Player* p, Map_Graph* map) : player(p), world(map) {}

void CommandPickUp::execute() {
    if (!player || !world) {
        std::cerr << "Error: Invalid player or map reference in CommandPickUp." << std::endl;
        return;
    }

    Entity* item = player->getCurrentLocation()->getEntityByName(arguments);
    if (item) {
        player->getInventory().addItem(item);
        player->getCurrentLocation()->removeEntity(item->getName()); 
        std::cout << "You picked up the " << item->getName() << "." << std::endl;
    }
    else {
        std::cout << "Cannot find " << arguments << " here." << std::endl;
    }
}
