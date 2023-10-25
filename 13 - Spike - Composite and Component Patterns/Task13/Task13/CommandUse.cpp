#include "CommandUse.h"
#include <iostream>
#include "HealAction.h"

CommandUse::CommandUse(Player* p, Map_Graph* map) : player(p), world(map) {}

void CommandUse::execute() {
    if (!player || !world) {
        std::cerr << "Error: Invalid player or map reference in CommandUse." << std::endl;
        return;
    }

    Entity* item = player->getInventory().getItemByName(arguments);
    if (item) {
        HealAction* healAction = dynamic_cast<HealAction*>(item->getComponent("Heal"));
        if (healAction) {
            healAction->execute();
            player->getInventory().removeItem(item);
            std::cout << "You used the " << arguments << " and feel rejuvenated!" << std::endl;
        }
        else {
            std::cout << "The " << arguments << " doesn't seem to have any effect." << std::endl;
        }
    }
    else {
        std::cout << "Cannot find " << arguments << " in your inventory." << std::endl;
    }
}
