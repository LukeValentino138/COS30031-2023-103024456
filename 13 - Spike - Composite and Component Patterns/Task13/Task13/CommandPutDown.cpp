#include "CommandPutDown.h"
#include <iostream>

CommandPutDown::CommandPutDown(Player* p, Map_Graph* map) : player(p), world(map) {}

void CommandPutDown::execute() {
    if (!player || !world) {
        std::cerr << "Error: Invalid player or map reference in CommandPutDown." << std::endl;
        return;
    }

    Entity* item = player->getInventory().getItemByName(arguments);

    if (item) {
        player->getInventory().removeItem(item);

        player->getCurrentLocation()->addEntity(item);

        std::cout << "You dropped the " << arguments << "." << std::endl;
    }
    else {
        std::cout << "You don't have a " << arguments << " in your inventory." << std::endl;
    }
}
