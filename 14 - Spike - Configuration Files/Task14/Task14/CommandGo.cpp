#include "CommandGo.h"
#include <iostream>

CommandGo::CommandGo(Player* player, Map_Graph* map) : player(player), map(map) {}

CommandGo::~CommandGo() {}

void CommandGo::execute() {
    if (!player || !map) {
        std::cerr << "Error: Invalid player or map reference in CommandGo." << std::endl;
        return;
    }

    Vertex* newLocation = map->movePlayer(player, arguments);
    if (newLocation) {
        player->setCurrentLocation(newLocation);
        std::cout << "You have moved to " << newLocation->getName() << "." << std::endl;
    }
    else {
        std::cout << "You can't go in that direction." << std::endl;
    }
}
