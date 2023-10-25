#include "CommandLook.h"
#include <iostream>

CommandLook::CommandLook(Player* player, Map_Graph* map) : player(player), map(map) {}

CommandLook::~CommandLook() {}

void CommandLook::execute() {
    if (!player || !map) {
        std::cerr << "Error: Invalid player or map reference in CommandLook." << std::endl;
        return;
    }

    if (arguments.empty()) {
        Vertex* location = player->getCurrentLocation();
        if (location) {
            location->print();
        }
        else {
            std::cout << "You seem to be in an unknown location." << std::endl;
        }
    }
    else {
        if (arguments.substr(0, 3) == "at ") {
            arguments = arguments.substr(3);
        }

        Vertex* location = player->getCurrentLocation();
        if (location && location->hasEntity(arguments)) {
            Entity* entity = location->getEntityByName(arguments);
            if (entity) {
                std::cout << "You see a(n) " << entity->getName() << std::endl;
            }
        }
        else {
            std::cout << "There is no " << arguments << " at this location." << std::endl;
        }
    }
}

