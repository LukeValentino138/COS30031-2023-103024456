#include "CommandInventory.h"
#include <iostream>

CommandInventory::CommandInventory(Player* player) : player(player) {}

CommandInventory::~CommandInventory() {}

void CommandInventory::execute() {
    if (!player) {
        std::cerr << "Error: Invalid player reference in InventoryCommand." << std::endl;
        return;
    }
    std::cout << "Your inventory:" << std::endl;
    player->getInventory().printInventory();
}
