#include "CommandLookIn.h"
#include "InspectContentsAction.h"  
#include <iostream>

CommandLookIn::CommandLookIn(Player* p) : player(p) {}

void CommandLookIn::execute() {
    if (!player) {
        std::cerr << "Error: Invalid player reference in CommandLookIn." << std::endl;
        return;
    }

    Entity* container = player->getInventory().getItemByName(arguments);

    if (container) {
        InspectContentsAction* inspectAction = dynamic_cast<InspectContentsAction*>(container->getComponent("Inspect Contents"));

        if (inspectAction) {
            inspectAction->execute();
        }
        else {
            std::cout << "The container " << arguments << " does not have an inspect action." << std::endl;
        }
    }
    else {
        std::cout << "Cannot find container " << arguments << " in your inventory." << std::endl;
    }
}
